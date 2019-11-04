/* ##### PART 1 ##### */

%schedule
schedule(monday,tbfo).
schedule(monday,logkom).
schedule(monday,algeo).
schedule(tuesday,orkom).
schedule(tuesday,matdis).
schedule(tuesday,alstrukdat).
schedule(wednesday,kwn).
schedule(wednesday,tbfo).
schedule(wednesday,algeo).
schedule(thursday,praktikum).
schedule(thursday,matdis).
schedule(thursday,alstrukdat).
schedule(friday,orkom).

%diff
difficulty(tbfo,extreme).
difficulty(logkom,medium).
difficulty(algeo,medium).
difficulty(orkom,hard).
difficulty(matdis,medium).
difficulty(alstrukdat,medium).
difficulty(kwn,easy).

%statements
classInformation(Day, Class, Diff) :-
    schedule(Day, Class),
    difficulty(Class,Diff).

/* ##### PART 2 ##### */

loves(romeo,juliet).
happy(juliet).

happy(romeo) :- 
    loves(juliet,romeo).

happy(romeo) :- 
    happy(juliet).


/* ##### PART 3: Structures ##### */
customer(tom, smith, 20.55).
customer(sally, smith, 120.55).

get_cust_bal(FName, LName) :-
    customer(FName, LName, Bal),
    write(FName), tab(1),
    format('~w owes us $~1f ~n', [LName,Bal]).

vertical(line(point(X, Y), point(X, Y))).


/* ##### PART 4: Recursion ##### */
parent(albert,bob).
parent(albert,betsy).
parent(bob,carl).
parent(bob,charlie).
parent(charlie,zack).

related(X,Y) :- parent(X,Y).
related(X,Y) :- parent(X,Z), related(Z,Y).
