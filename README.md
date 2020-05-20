# Project Coronavirus Statistics

#### Table of Contents
- [Problem](#problem)
- [Configuration](#configuration)
- [How will your task be judged ?](#howtojudged)
- [Editorial](#editorial)


## Problem

   *The COVID19 pandemic situation is very complex around the world, so it aims to provide information to everyone in the fastest and most accurate way. The government has asked you - a future programmer studying at ITMO University to solve the following problem:*

   Assuming there are N cities in the world, numbered from 1 to N, initially the number of cases for each city is zero. The government requires you to process Q queries, each of which will be one of the following:

* Type 1 : Update a city with index X has Y more new cases.
* Type 2 : Update city with index X has Y more recovering cases.
* Type 3 : Update city with index X has Y more death.
* Type 4 : In all cities there are more than 0 cases, ask for the K-th best city information.

  Considering cities A and B, city A is called better than city B if A is the first one that satisfies the following conditions:
  - City A has fewer cases than city B.
  - City A has more recovery cases than city B.
  - City A has fewer deaths than city B.
  - City A has a smaller index than city B.
  
   For example, if A has 10 cases, 6 recovered , 3 died , and the index is 2. B has 10 cases, 3 recovered, 4 died, the index is 3. Then A will be considered better than B because A has more recovery cases than B. 
* Type 5 : Ask for the number of cities without any cases.
* Type 6 : In all cities there are more than 0 cases,ask for the city has the most number of recovery cases and the number of recovery cases.If there are many such cities give the city the smallest index.
* Type 7 : In all cities there are more than 0 cases,ask for the city has the most number of death and the number of death.If there are many such cities give the city the smallest index.

*All queries are related to each other.*

#### Input 
The first line contains 2 numbers N and Q. The number of cities and queries you need to solve, respectively.

In the next Q lines, each line will be one of the following seven forms:
  - *q 1 X Y* - corresponding query type 1
  - *q 2 X Y* - corresponding query type 2
  - *q 3 X Y* - corresponding query type 3
  - *? 4 K* - corresponding query type 4
  - *? 5* - corresponding query type 5
  - *? 6* - corresponding query type 6 
  - *? 7* - corresponding query type 7
  
#### Output 
* With type 4 query print out as follows:
```
For example , the query is "? 4 1".And the 1st best city is a city with an index of 5, 
the number of cases is 8, the number of recovered cases is 1 and the number of deaths is 2
.Then the output will be:

Query ? 4 1 :
The answer is the city with the index 5 
- Information of the city 5 -
-> Number of current patients : 8
-> Has recovered : 1
-> Was dead : 2
```

* With type 5 query print out as follows:
```
For example , the query is "? 5".And the number of cities without any cases is 10
.Then the output will be:

Query ? 5 :
The number of safe cities is 10
```

* With type 6 query print out as follows:
```
- For example , the query is "? 6".And the city with the highest number of people recovering
is the city with the index 20, the number of people who have recovered is 84. Then the output will be:

Query ? 6 :
The city with the highest recovery is city with the index 20
Quantity: 84 people

- If no case of recovery is recorded, print the following:

Query ? 6 :
Currently, no recovery cases have been recorded
```

* With type 7 query print out as follows:
```
- For example, the query is "? 7". And the city with the most deaths
is the city with the index of 20, the number of deaths is 84. The output will be:

Query ? 7 :
The city with the highest death is city with the index 20
Quantity: 84 people

- If no deaths have been recorded,print the following:

Query ? 7 :
Currently, no deaths have been recorded
```

*Each query is separated by a space.*

#### Limits 
*Time limit: 25 seconds per test set for C++ and 35 seconds per test set for Python/Java*

*1 <= N,Q <= 100000*

*1 <= X <= N*

*1 <= Y <= 15000*


```text
- With the queries type 2,3 ,test sets ensures that the number of recovery or death cases
never exceeds the current number of cases in the city.

- The test set always ensures at least one query is "? ... " .

- For query type 4 , ensures that K >= 1 and K not exceeded the number of cities with more than 0 cases .

- For each type 6,7 query , ensure that at least one city has more than 0 cases.

 ```

*Test set 1 (pretest)*

1 <= N <= 50

1 <= Q <= 100

<br>

*Test set 2 (test)*

100 <= N,Q <= 100000

<br>

*Sample*

Input :
```
5 12
q 1 2 22
q 2 2 5
? 4 1
? 7
q 1 3 17
q 1 1 22
q 2 3 3
? 4 3
q 1 4 40
? 4 1
? 6
? 4 4
```

Output :
```
Query ? 4 1 :
The answer is the city with the index 2 
- Information of the city 2 -
-> Number of current patients : 17
-> Has recovered : 5
-> Was dead : 0

Query ? 7 :
Currently, no deaths have been recorded

Query ? 4 3 :
The answer is the city with the index 1 
- Information of the city 1 -
-> Number of current patients : 22
-> Has recovered : 0
-> Was dead : 0

Query ? 4 1 :
The answer is the city with the index 3 
- Information of the city 3 -
-> Number of current patients : 14
-> Has recovered : 3
-> Was dead : 0

Query ? 6 :
The city with the highest recovery is city with the index 2
Quantity: 5 people

Query ? 4 4 :
The answer is the city with the index 4 
- Information of the city 4 -
-> Number of current patients : 40
-> Has recovered : 0
-> Was dead : 0

```

## Configuration

* All `.cpp`,`.py` or `.java` scripts should be placed in `src/main` directory.
* All tests with small data limits should be placed in `src/test/coronavirus_statistics_test/pretest` directory.
* All tests with large data limits should be placed in `src/test/coronavirus_statistics_test/test` directory.
* Each test is basically a directory with two files `.inp` and `.out` .

For example, you have a script file `corona.cpp` , the test sets was provided.So, source structure should be the following :

```
src
├── main
│   └── corona.cpp
└── test
    └── coronavirus_statistics_test
        ├── pretest
        │   ├── pretest_1
        │   │   ├── pretest.inp
        │   │   └── pretest.out
        │   ├── pretest_2
        │   │   ├── pretest.inp
        │   │   └── pretest.out
        │   ├── pretest_3
        │   │   ├── pretest.inp
        │   │   └── pretest.out
        │   .
        │   .
        │   .	
        │   ├── pretest_49
        │   │   ├── pretest.inp
        │   │   └── pretest.out
        │   └── pretest_50
        │       ├── pretest.inp
        │       └── pretest.out
        └── test
            ├── test_1
            │   ├── test.inp
            │   └── test.out
            ├── test_2
            │   ├── test.inp
            │   └── test.out
            ├── test_3
            │   ├── test.inp
            │   └── test.out
            .
            .
            .
            ├── test_49
            │   ├── test.inp
            │   └── test.out
            └── test_50
                ├── test.inp
                └── test.out
runtest.py
solve.sh
```

<a name="howtojudged"/>

## How will your task be judged ?

* I use [Travis CI](https://travis-ci.com/) to evaluate your task.
* The `runtest.py` script file will be responsible for finding your task in the `src/main` directory, checking if your task has exceeded the time limit ([TLE](https://en.wiktionary.org/wiki/TLE)), and comparing your answer with my answer.
* If you give a different answer to my answer, your task will be considered a failure.
* If your task exceeds the time limit , your task will be considered a failure.
* If you do not pass **test set 1 (pretest)**, you will not be able to continue **test set 2 (test)**.
* If you give a different answer to me. For example, with `pretest_10` you gave a different answer to me,so in the `src/test/coronavirus_statistics_test/pretest_10` directory, your answer will be written in the file `your_output.out`.
* You are only considered to pass if you pass both test sets. Travis CI will evaluate this.

#### Demo 

<details>
  <summary> Success output (passed both test sets) </summary> 
<code> ----> Compiling main.cpp </code> <br>
<code> Running pretest </code> <br>
<code> > running on pretest_1 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_2 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_3 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_4 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_5 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_6 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_7 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_8 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_9 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_10 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_11 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_12 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_13 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_14 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_15 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_16 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_17 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_18 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_19 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_20 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_21 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_22 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_23 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_24 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_25 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_26 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_27 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_28 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_29 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_30 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_31 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_32 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_33 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_34 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_35 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_36 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_37 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_38 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_39 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_40 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_41 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_42 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_43 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_44 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_45 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_46 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_47 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_48 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_49 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_50 </code> <br>
<code> > status : ok! </code> <br>

<code> Status : accepted </code> <br> 

<code> ----> Compiling main.cpp </code> <br>
<code> Running test </code> <br>
<code> > running on test_1 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_2 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_3 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_4 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_5 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_6 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_7 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_8 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_9 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_10 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_11 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_12 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_13 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_14 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_15 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_16 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_17 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_18 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_19 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_20 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_21 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_22 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_23 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_24 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_25 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_26 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_27 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_28 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_29 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_30 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_31 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_32 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_33 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_34 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_35 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_36 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_37 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_38 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_39 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_40 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_41 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_42 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_43 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_44 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_45 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_46 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_47 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_48 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_49 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_50 </code> <br>
<code> > status : ok! </code> <br>

<code> Status : accepted </code> <br> 

</details>  

<details>
  <summary> Failure output (failed on test_13)</summary>
  
  <code> ----> Compiling main.cpp </code> <br>
<code> Running pretest </code> <br>
<code> > running on pretest_1 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_2 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_3 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_4 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_5 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_6 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_7 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_8 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_9 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_10 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_11 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_12 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_13 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_14 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_15 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_16 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_17 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_18 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_19 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_20 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_21 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_22 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_23 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_24 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_25 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_26 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_27 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_28 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_29 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_30 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_31 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_32 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_33 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_34 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_35 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_36 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_37 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_38 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_39 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_40 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_41 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_42 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_43 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_44 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_45 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_46 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_47 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_48 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_49 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_50 </code> <br>
<code> > status : ok! </code> <br>

<code> Status : accepted </code> <br> 

<code> ----> Compiling main.cpp </code> <br>
<code> Running test </code> <br>
<code> > running on test_1 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_2 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_3 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_4 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_5 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_6 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_7 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_8 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_9 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_10 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_11 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_12 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_13 </code> <br>
<code> > status : failed on test_13 </code> <br>

<code> > running on test_14 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_15 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_16 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_17 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_18 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_19 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_20 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_21 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_22 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_23 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_24 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_25 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_26 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_27 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_28 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_29 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_30 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_31 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_32 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_33 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_34 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_35 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_36 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_37 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_38 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_39 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_40 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_41 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_42 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_43 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_44 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_45 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_46 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_47 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_48 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_49 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on test_50 </code> <br>
<code> > status : ok! </code> <br>

<code> Status : failed </code> <br>

</details>

<details>
  <summary> TLE output (time limit exceeded on pretest_5)</summary>
  
<code> ----> Compiling main.cpp </code> <br>
<code> Running pretest </code> <br>
<code> > running on pretest_1 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_2 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_3 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_4 </code> <br>
<code> > status : ok! </code> <br>

<code> > running on pretest_5 </code> <br>
<code> Time Limit Exceeded </code> <br>

</details> 

#### Script to run tests (in Git Bash on Linux) 

* Run all test sets
```bash
bash solve.sh
```

* Run a particular test set with a certain number of tests.

For example, you want to run the first 20 tests in test set 2 (test),syntax will be :
```bash
python3 runtest.py test 20
```

## Editorial

<details>
  <summary> Hint 1</summary>
  Is there a data structure that helps you quickly insert, delete, search, or not?
</details>


<details>
  <summary> Hint 2</summary>
  Yeah , that is <a href = "https://en.wikipedia.org/wiki/AVL_tree">AVL tree</a> <br>
  You can interact with avl tree <a href = "https://visualgo.net/en/bst">here</a>
</details>  

<details>
  <summary> Solution</summary>
  <br>
  <p> <b><i> Prerequisite : AVL tree and its basic operations such as insert, delete, find a given key. </i></b></p> <br>
  
  <p> In this problem I will use the self-balancing binary search tree (AVL tree) to handle all 7 types of queries. </p>
  
 -First of all, defining a <code>Key</code> will include the following information:
    <ul>
        <li> cur - number of current cases. </li>
        <li> fine - the number of cases recovered . </li>
        <li> dead - the numer of deaths. </li>
        <li> city_id - index of the city . </li>
    </ul> 
    
  <p> -To compare two keys with each other, we use the comparison which has been described in the problem. </p> 
  
  <p> -It can be seen that a <code>Key</code> will represent a city. </p> 
  
  -Next, define the information that each node on the AVL tree will store: 
  <ul> 
      <li> key - information of a city </li>
      <li> height - The height of the subtree whose root node is the current node .</li>
      <li> balance - Difference in height of left subtree and right subtree. </li>
      <li> size_subtree - the number of nodes in the subtree whose root node is the current node.</li>
      <li> max_fine - contains a pair of values, the highest number of recovered cases and the smallest index of the city     with the highest number of recovered cases in the subtree whose root node is the current node. </li> 
      <li> max_dead - contains a pair of values, which is the highest number of deaths and the smallest index of the city with the highest number of deaths in the subtree whose root node is the current node. </li>
      <li> left , right - a pointer to the left subtree and to the right subtree </li>
  </ul>
    
  <p> -Now, we will maintain an AVL tree, each node of the tree represents a city with more than 0 cases and the information defined above. To process type 1, 2 and 3 queries, we only need to perform operations such as searching, inserting, deleting a node. For example, when a city has more cases we will add a node representing that city to the tree if the city is not already in the tree, or delete the old representative node and add a new representative node. Or when the number of recovering cases is equal to the current number of cases in the city, we also have to delete the representative node of that city. </p>
  
  <p> -To handle type queries 4,5,6,7, we must find a way to aggregate information on the tree. In other words, the information needs to be aggregated from the subtree to the its root . </p>
  <img src="https://scontent-hel2-1.xx.fbcdn.net/v/t1.15752-9/98338744_610742679516153_7130993557996830720_n.png?_nc_cat=110&_nc_sid=b96e70&_nc_ohc=H8cneVSlCDEAX__PKfj&_nc_ht=scontent-hel2-1.xx&oh=4f8ed98df60f7fe5ed5c9a2c2580e76b&oe=5EEA741B">
  <p align="center">Example - an AVL tree,the number on each node represents the city index. </p> 
  
  <p>Consider the node with index 50,we need to aggregate information from its subtree </p>
  <ol>
    <li> key will be information of city with index 50 </li>
    <li> height = 1 + max (height of left subtree , height of right subtree ) = 1 + max(2,2) = 3 </li>
    <li> balance = (height of left subtree) - (height of right subtree) = 2 - 2 = 0 </li>
    <li> size_subtree = 1 + (size of left subtree) + (size of right subtree) = 1 + 3 + 3 = 7 </li>
    <li> max_fine = Maximum values of (key.fine, key.city_id) and max ( max_fine of left subtree , max_fine of right subtree) </li>
    <li> max_dead = Maximum values of (key.dead, key.city_id) and max ( max_dead of left subtree , max_dead of right subtree) </li>
  </ol>
  
  <p> After aggregating information on the tree, the query 5,6,7 can be easily answered by retrieving information from the root node.</p>
  
  <p> Observing the properties of the AVL tree,for each node the nodes on the left subtree will have smaller values and the nodes on the right subtree will have greater value. So if a node is a Kth node, then the size of the left subtree must be K - 1. From here we have the solution to find the Kth node as follows: go from the root of the tree, to a certain node, if the left subtree is the size K - 1 then the current node is the result, otherwise if K > (size of left subtree + 1) move to right subtree and K = K - (size of left subtree + 1), otherwise move to left subtree.</p>
  
  <a href="https://paste.ubuntu.com/p/ddFCwhp5Qc/">Code (C++) </a>
</details> 

<details>
  <summary> This is the code used to create the test </summary>
  <a href="https://paste.ubuntu.com/p/TRS3hNQbSN/">gentest.py </a>
  <p> you can customize lines 18,19 , that means creat test from test_LOW to test_HIGH. </p>
  <p> you can customize lines 44,45,46 to change data limits. </p>
  <p> gentest.py creat a directory with name test_mode in current directory </p> 
  <p> Script in git bash Linux : <code> python3 gentest.py test </code> </p>
  <p> here i used a file <code>actual_sol.cpp</code> in the same directory with <code>gentest.py</code> to compute answer for input which was created.If you use other languge , just customize line 129 to change way to compile , and line 135 to run . </p>
</details>  

### Thank you for reading!!!
