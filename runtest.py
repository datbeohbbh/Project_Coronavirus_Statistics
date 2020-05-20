import subprocess
import os
import re
import sys
import multiprocessing
import time
import threading

test_mode = sys.argv[1]
#test_mode = "pretest"
#NUM_TEST = 20
NUM_TEST = int(sys.argv[2])

SUCCESS = 0
FAIL = 1

allLanguageSupport = ["cpp","py","java"]

p = subprocess.Popen(["pwd"],stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
cur_path = p.communicate()[0].decode("utf-8")
cur_path = cur_path[0 : len(cur_path) - 1]
subprocess.Popen(["chmod","-R","744",cur_path])

src_directory = cur_path + "/src"
task_directory = src_directory + "/main"
name_test_dir = "test/coronavirus_statistics_test"
test_directory = src_directory + "/" + name_test_dir + "/" + test_mode

contestant_out = "your_output.out"

executable = task_directory + "/executable"
os.system("mkdir -p" + " " + executable)

test = []

TIME_LIMIT_CPP = 25
TIME_LIMIT_PY = 35
TIME_LIMIT_JAVA = 35

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

def creatListOfTest():
    for i in range(1,NUM_TEST + 1) :
        test.append(test_mode + "_" + str(i))

def failMessage(test_id) :
    print(f"> status : {bcolors.FAIL}failed on " + test_id)
    print(f"{bcolors.ENDC}")

def isSource(tail) :
    find = subprocess.Popen(["ls",task_directory],stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    name = find.communicate()[0].decode("utf-8").split()
    if len(name) == 0 :  return
    for element in name :
        flag = re.match("^\w+\." + tail + "$",element)
        if flag :
            if(tail != "py"):
                return flag.string
            elif (flag.string != "gentest.py" and flag.string != "runtest.py") :
                return flag.string
    return 0

def toList(file_name) :
    f = open(file_name,"r")
    ret = list(map(lambda line : line.rstrip(),f))
    f.close()
    while len(ret) > 0 and ret[len(ret) - 1] == '' :
        del ret[len(ret) - 1]
    return ret

def compare(actual_output,expected_output) :
    if toList(actual_output) == toList(expected_output) :
        return True
    else :
        return False

def process(test_id,li) :
    print("> running on", test_id, end="\n")
    file = "/".join([test_directory, test_id, ""])
    actual_output = file + contestant_out
    expected_output = file + test_mode + ".out"
    os.system(" ".join(li))
    ok = compare(actual_output, expected_output)
    if (ok == False):
        failMessage(test_id)
    else :
    	print("> status : ok!\n")

def runTestCpp(cpp_name) :
    subprocess.Popen(["g++",task_directory + "/" + cpp_name,"-o",executable + "/main"])
    os.system("sleep 2")
    for test_id in test :
        file = "/".join([test_directory, test_id, ""])
        input = file + test_mode + ".inp"
        actual_output = file + contestant_out
        li = ["cd",executable,"&&","./main","<",input,">",actual_output]
        process(test_id,li)

def runTestPy(py_name) :
    os.system("sleep 2")
    for test_id in test :
        file = "/".join([test_directory, test_id, ""])
        input = file + test_mode + ".inp"
        actual_output = file + contestant_out
        li = ["python3",task_directory + "/" + py_name,"<",input,">",actual_output]
        process(test_id,li)

def runTestJava(java_name):
    subprocess.Popen(["javac","-d",executable,task_directory + "/" + java_name])
    os.system("sleep 2")
    fname = java_name[0 : len(java_name) - 5]
    for test_id in test :
        file = "/".join([test_directory, test_id, ""])
        input = file + test_mode + ".inp"
        actual_output = file + contestant_out
        li = ["cd", executable, "&&", "java",fname, "<", input, ">", actual_output]
        process(test_id,li)

def Cpp(source) :
    cpp = multiprocessing.Process(target=runTestCpp, name="runTestCpp", args=(source,))
    cpp.start()
    cpp.join(TIME_LIMIT_CPP)
    flag = cpp.is_alive()
    if flag :
        cpp.terminate()
        cpp.join()
    return flag

def Python(source) :
    python = multiprocessing.Process(target = runTestPy,name = "runTestPy",args=(source,))
    python.start()
    python.join(TIME_LIMIT_PY)
    flag = python.is_alive()
    if flag :
        python.terminate()
        python.join()
    return flag

def Java(source) :
    java = multiprocessing.Process(target = runTestJava,name = "runtestJava",args=(source,))
    java.start()
    java.join(TIME_LIMIT_JAVA)
    flag = java.is_alive()
    if flag :
        java.terminate()
        java.join()
    return flag

def runTest(lang,source):
    if lang == "cpp" :
        #runTestCpp(source)
        return Cpp(source)
    elif lang == "py" :
        #runTestPy(source)
        return Python(source)
    else :
        #runTestJava(source)
        return Java(source)

def checkTest():
    for test_id in test :
        file = "/".join([test_directory, test_id, ""])
        actual_output = file + contestant_out
        expected_output = file + test_mode + ".out"
        ok = compare(actual_output, expected_output)
        if ok == False :
            return 1
        os.system("rm" + " " + actual_output)
    return 0

def main():
    creatListOfTest()

    runned = False
    for lang in allLanguageSupport :
        if isSource(lang) != 0:
            source = isSource(lang)
            print("----> Compiling " + source,end = "\n")
            print("Running",test_mode,end = "\n")
            flag = runTest(lang,source)
            if flag == 0:
                  flag = checkTest()
                  if flag == 0 :
                    print(f"{bcolors.OKGREEN}Status : accepted{bcolors.ENDC}",end = "\n")
                  else :
                      print(f"{bcolors.FAIL}Status : failed{bcolors.ENDC}", end="\n")
                      return 1
            else :
                print(f"{bcolors.WARNING}Time Limit Exceeded{bcolors.ENDC}")
                return 1
            print()
            runned = True

    #os.system(" ".join(["rm","-Rd",executable,"2>/dev/null"]))
    if runned == False :
        print("Can not find your language :(")
        return 1
    return 0

if __name__ == '__main__':
    t = main()
    sys.exit(t)


