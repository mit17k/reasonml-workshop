// 01-introduction - hello world

let () = print_endline("\n01-introduction");
let () = print_endline("Hello World!");

// 02-basic_types
let () = print_endline("\n02-basic_types");
let intAverage = (x, y) => ((x + y) / 2);
let floatAverage = (x, y) => ((x +. y) /. 2.);

let x1 = 10;
let y2 = 20;

let resultIntAverage = intAverage(x1, y2);
let () = print_endline("Int Average Result : " ++ string_of_int(resultIntAverage));

let x2 = 10.;
let y2 = 20.;

let resultFloatAverage = floatAverage(x2, y2);
let () = print_endline("Float Average Result : " ++ Js.Float.toString(resultFloatAverage));

let getName = (f, l) => f ++ " " ++ l;

let firstName = "Mitesh";
let lastName = "Khare";

let fullName = getName(firstName, lastName);
let () = print_endline("Full Name : " ++ fullName);

Test.runAll([
  (intAverage(5, 5) == 5, "intAverage"),
  (floatAverage(5., 5.) == 5., "floatAverage"),
  (getName("a", "b") == "a b", "getName")
]);

// 03-define_functions
let () = print_endline("\n03-define_functions");

let plus = (x, y) => x + y;
let times = (x, y) => x * y;
let minus = (x, y) => x - y;
let divide = (x, y) => x / y;

let plusResult = plus(5, 5);
let () = print_endline("Plus Result for 5,5 : " ++ string_of_int(plusResult));

let timesResult = times(5, 5);
let () = print_endline("Times Result for 5,5 : " ++ string_of_int(timesResult));

let minusResult = minus(5, 5);
let () = print_endline("Plus Result for 5,5 : " ++ string_of_int(minusResult));

let divideResult = divide(5, 5);
let () = print_endline("Plus Result for 5,5 : " ++ string_of_int(divideResult));

Test.runAll([
  (plus(1, 1) == 2, "plus"),
  (plus(50, -1) == 49, "plus"),
  (times(8, 8) == 64, "times"),
  (times(2, -1024) == (-2048), "times"),
  (minus(-2, 2) == (-4), "minus"),
  (minus(1337, 337) == 1000, "minus"),
  (divide(1024, 2) == 512, "divide"),
  (divide(31337, 31) == 1010, "divide"),
]);

// 04-call_functions
let () = print_endline("\n04-call_functions");

let average = (x, y) => {
  let sum = plus(x, y);
  let avg = divide(sum, 2);
  avg;
};

let averageResult = average(5, 5);
let () = print_endline("Average Result for 5,5 : " ++ string_of_int(averageResult));

Test.runAll([
  (average(5, 5) == 5, "average"),
  (average(50, 100) == 75, "average"),
]);

// 05-twice
let () = print_endline("\n05-twice");

let add1 = plus(1);
let square = x => x * x;

let add1Result = add1(5);
let squareResult = square(5);

let () = print_endline("Add 1 Result for 5 : " ++ string_of_int(add1Result));
let () = print_endline("Square Result for 5 : " ++ string_of_int(squareResult));

let twice = (f, x) => {
  let r1 = f(x);
  let r2 = f(r1);
  r2
};

let add2 = x => twice(add1, x);
let raiseToTheFourth = x => twice(square, x);

let add2Result = add2(5);
let raiseToFourthResult = raiseToTheFourth(5);

let () = print_endline("Add 2 Result for 5 : " ++ string_of_int(add2Result));
let () = print_endline("Raise To Fourth Result for 5 : " ++ string_of_int(raiseToFourthResult));

Test.runAll([
  (add1(4) == 5, "add1"),
  (square(4) == 16, "square"),
  (square(-4) == 16, "square"),
  (twice(add1, 3) == 5, "twice"),
  (add2(1335) == 1337, "add2"),
  (raiseToTheFourth(1) == 1, "raiseToTheFourth"),
  (raiseToTheFourth(10) == 10000, "raiseToTheFourth"),
]);

// 06-pattern-matching
let () = print_endline("\n06-pattern-matching");

let nonZero = x => switch x {
  | 0 => false
  | _ => true
  };

let nonZeroResult = nonZero(5);
let () = print_endline("Non Zero Result for 5 : " ++ string_of_bool(nonZeroResult));

Test.runAll([
  (nonZero(0) == false, "non zero"),
  (nonZero(500) == true, "non zero"),
  (nonZero(-400) == true, "non zero"),
]);

// 07-simple_recursion
let () = print_endline("\n07-simple_recursion");

let rec factorial = x => {
  assert (x >= 0);
  switch (x) {
  | 0 => 1
  | _ => x * factorial(x - 1)
  };
};

let factorialResult = factorial(5);
let () = print_endline("Factorial Result for 5 : " ++ string_of_int(factorialResult));

Test.runAll([
  (factorial(0) == 1, "factorial"),
  (factorial(5) == 120, "factorial"),
  (factorial(12) == 479001600, "factorial"),
]);

// 08-list_intro
let () = print_endline("\n08-list_intro");

let rec lSum = lst => switch lst {
  | [] => 0
  | [hd, ...tl] => hd + lSum(tl)
};

let lSumResult = lSum([5, 5, 5]);
let () = print_endline("List Sum Result for 5,5,5 : " ++ string_of_int(lSumResult));

Test.runAll([
  (lSum([]) == 0, "sum"),
  (lSum([55]) == 55, "sum"),
  (lSum([5, (-5), 1, (-1)]) == 0, "sum"),
  (lSum([5, 5, 1, 1]) == 12, "sum"),
]);

// 09-list_range
let () = print_endline("\n09-list_range");
let rec range = (from, to_) => {
  let diff = to_ - from;
  switch diff {
  | 0 => []
  | _ => [from] @ range(from + 1, to_)
  };
};

let listRangeResult = range(-5, 5);
let () = {
  print_endline("List Range Result for -5,5 : ");
  Js.log(Array.of_list(listRangeResult))
};

Test.runAll([
  (range(1, 4) == [1, 2, 3], "range"),
  (range(-5, 3) == [(-5), (-4), (-3), (-2), (-1), 0, 1, 2], "range"),
]);

// 10-list_product
let () = print_endline("\n10-list_product");

let rec lProduct = xs =>
  switch (xs) {
  | [] => 1
  | [hd, ...tl] => hd * lProduct(tl)
  };

let lProductResult = lProduct([5, 5, 5]);
let () = print_endline("List Product Result for 5,5,5 : " ++ string_of_int(lProductResult));

Test.runAll([
  (lProduct([]) == 1, "product"),
  (lProduct([55]) == 55, "product"),
  (lProduct([5, (-5), 1, (-1)]) == 25, "product"),
  (lProduct([5, 5, 1, 1]) == 25, "product"),
]);

// 11-sum_product
let () = print_endline("\n11-sum_product");

let rec every = (answer, combine, xs) => 
  switch xs {
  | [] => answer
  | [hd, ...tl] => combine(answer, every(hd, combine, tl))
  };

let simplerSum = xs => every(0, plus, xs);

let simplerSumResult = simplerSum([5, 5, 5]);
let () = print_endline("Simpler Sum Result for 5,5,5 : " ++ string_of_int(simplerSumResult));

let simplerProduct = xs => every(1, times, xs);

let simplerProductResult = simplerProduct([5, 5, 5]);
let () = print_endline("Simpler Product Result for 5,5,5 : " ++ string_of_int(simplerProductResult));

Test.runAll([
  (simplerProduct([]) == 1, "simpler product"),
  (simplerProduct([55]) == 55, "simpler product"),
  (simplerProduct([5, (-5), 1, (-1)]) == 25, "simpler product"),
  (simplerProduct([5, 5, 1, 1]) == 25, "simpler product"),
  (simplerSum([]) == 0, "simpler sum"),
  (simplerSum([55]) == 55, "simpler sum"),
  (simplerSum([5, (-5), 1, (-1)]) == 0, "simpler sum"),
  (simplerSum([5, 5, 1, 1]) == 12, "simpler sum"),
]);

// 12-list_min
let () = print_endline("\n12-list_min");

let rec largest = xs =>
  switch (xs) {
  | [] => neg_infinity
  | [x, ...rest] => max(x, largest(rest))
  };

let largestResult = largest([5., 50.]);
let () = print_endline("Largest Result for 5,50 : " ++ Js.Float.toString(largestResult));

let rec smallest = xs =>
  switch (xs) {
  | [] => infinity
  | [x, ...rest] => min(x, smallest(rest))
  };

let smallestResult = smallest([5., 50.]);
let () = print_endline("Smallest Result for 5,50 : " ++ Js.Float.toString(smallestResult));

Test.runAll([
  (smallest([]) == infinity, "smallest"),
  (smallest([55.]) == 55., "smallest"),
  (smallest([5., (-5.), 1., (-1.)]) == (-5.), "smallest"),
  (smallest([5., 5., 1., 1.]) == 1., "smallest"),
]);

// 13-largest_smallest
let () = print_endline("\n13-largest_smallest");

let sLargest = (x, y) => max(x, y);
let simplerLargest = xs => every(neg_infinity, sLargest, xs);

let simplerLargestResult = simplerLargest([5., 50.]);
let () = print_endline("Simpler Largest Result for 5,50 : " ++ Js.Float.toString(simplerLargestResult));

let sSmallest = (x, y) => min(x, y);
let simplerSmallest = xs => every(infinity, sSmallest, xs);

let simplerSmallestResult = simplerSmallest([5., 50.]);
let () = print_endline("Simpler Smallest Result for 5,50 : " ++ Js.Float.toString(simplerSmallestResult));

Test.runAll([
  (simplerSmallest([]) == infinity, "simpler smallest"),
  (simplerSmallest([55.]) == 55., "simpler smallest"),
  (simplerSmallest([5., (-5.), 1., (-1.)]) == (-5.), "simpler smallest"),
  (simplerSmallest([5., 5., 1., 1.]) == 1., "simpler smallest"),
  (simplerLargest([]) == neg_infinity, "simpler largest"),
  (simplerLargest([55.]) == 55., "simpler largest"),
  (simplerLargest([5., (-5.), 1., (-1.)]) == 5., "simpler largest"),
  (simplerLargest([5., 5., 1., 1.]) == 5., "simpler largest"),
]);

// 14-variants
let () = print_endline("\n14-variants");

type cardValue =
  | Ace
  | King
  | Queen
  | Jack
  | Number(int);

let cardValueToScore = cardValue => 
  switch (cardValue) {
  | Ace => 11
  | King => 10
  | Queen => 10
  | Jack => 10
  | Number(i) => i
  };

let cardValueToScoreResult = cardValueToScore(Ace);
let () = print_endline("Card Value To Score Result for Ace : " ++ string_of_int(cardValueToScoreResult));

Test.runAll([
  (cardValueToScore(Ace) == 11, "card value to score"),
  (cardValueToScore(King) == 10, "card value to score"),
  (cardValueToScore(Queen) == 10, "card value to score"),
  (cardValueToScore(Jack) == 10, "card value to score"),
  (cardValueToScore(Number(5)) == 5, "card value to score"),
]);

// 15-tuples
let () = print_endline("\n15-tuples");

type pair('a) = ('a, 'a);
type coordinate = pair(int);

let addTuples = (coord1, coord2) => {
  let (x1, y1) = coord1;
  let (x2, y2) = coord2;
  (x1 + x2, y1 + y2)
};

let addTuplesResult = addTuples((5, 10), (5, 10));
let () = {
  print_endline("Add Tuples Result for (5, 10), (5, 10) : ");
  Js.log(addTuplesResult);
}

let firstTuple = pair => {
  let (first, _) = pair;
  first
};

let firstTupleResult = firstTuple((5, 10));
let () = print_endline("First Tuple Result for 5,10 : " ++ string_of_int(firstTupleResult));

let secondTuple = pair => {
  let (_, second) = pair;
  second
};

let secondTupleResult = secondTuple((5, 10));
let () = print_endline("Second Tuple Result for 5,10 : " ++ string_of_int(secondTupleResult));

Test.runAll([
  (addTuples((1, 2), (3, 4)) == (4, 6), "add"),
  (firstTuple(("foo", "bar")) == "foo", "first"),
  (secondTuple(('a', 'b')) == 'b', "second"),
]);

// 16-labelled_arguments
let () = print_endline("\n16-labelled_arguments");

let modulo = (~dividend, ~divisor) => dividend mod divisor;

let moduloResult = modulo(~dividend=5, ~divisor=5);
let () = print_endline("Modulo Result for 5,5 : " ++ string_of_int(moduloResult));

Test.runAll([
  (modulo(~dividend=17, ~divisor=5) == 2, "modulo"),
  (modulo(~dividend=99, ~divisor=9) == 0, "modulo"),
]);

// 17-options
let () = print_endline("\n17-options");

type option('a) =
  | None
  | Some('a);

let safeDivide = (~dividend, ~divisor) =>
  switch divisor {
  | 0 => None
  | _ => Some(divide(dividend, divisor))
  };

let safeDivideResult = safeDivide(~dividend=5, ~divisor=0);
let () = {
  print_endline("Safe Divide Result for 5 / 0 : ");
  Js.log(safeDivideResult);
};

Test.runAll([
  (
    switch (safeDivide(~dividend=3, ~divisor=2)) {
    | Some(1) => true
    | _ => false
    },
    "safe divide",
  ),
  (
    switch (safeDivide(~dividend=3, ~divisor=0)) {
    | None => true
    | _ => false
    },
    "safe divide",
  ),
]);

// 18-anonymous_functions
let () = print_endline("\n18-anonymous_functions");

let applyIfNonzero = (f, i) => 
  switch i {
  | 0 => 0
  | _ => f(i)
  };

let applyIfNonzeroTest = applyIfNonzero(add1, 5);
let () = print_endline("Apply If Non Zero Result for add1,5 : " ++ string_of_int(applyIfNonzeroTest));

Test.runAll([
  (applyIfNonzero(x => 10 / x, 0) == 0, "apply if non-zero"),
  (applyIfNonzero(x => 10 / x, 5) == 2, "apply if non-zero"),
]);

// 19-list_operations
let () = print_endline("\n19-list_operations");

let myNewInts = ints => List.map(add1, ints);

let myNewIntsResult = myNewInts([5, 6, 7]);
let () = {
  print_endline("New Ints Result for 5,6,7 : ");
  Js.log(Array.of_list(myNewIntsResult))
};

let numEvenInts = ints => List.fold_left((total, myInt) => {
  let m = modulo(~dividend=myInt, ~divisor=2);
  switch m {
  | 0 => total + 1
  | _ => total
  };
}, 0, ints);

let numEvenIntsResult = numEvenInts([5, 6, 7]);
let () = print_endline("Num Even Ints Result for 5,6,7 : " ++ string_of_int(numEvenIntsResult));

let myInts: list(int) = [1, 2, 3, 4, 5];
Test.runAll([
  (myNewInts(myInts) == [2, 3, 4, 5, 6], "my new ints"),
  (numEvenInts(myInts) == 2, "num even ints"),
]);

// 20-reading_sigs
let () = print_endline("\n20-reading_sigs");

module Fraction: {
  type t;
  let create: (~numerator: int, ~denominator: int) => t;
  let value: t => float
} = {
  type t = (int, int);
  let create = (~numerator, ~denominator) => (numerator, denominator);
  let value = ((numerator, denominator)) =>
    float_of_int(numerator) /. float_of_int(denominator);
};

Test.runAll([
  (
    Fraction.value(Fraction.create(~numerator=5, ~denominator=2)) == 2.5,
    "Fraction.value",
  ),
  (
    Fraction.value(Fraction.create(~numerator=4, ~denominator=10)) == 0.4,
    "Fraction.value",
  ),
]);

// 21-writing_list_operations
let () = print_endline("\n21-writing_list_operations");

module MyList: {
  /*
    map(f, list) takes a function [f] from ('a => 'b) and a list('a) and
    returns a list('b) (e.g. [f] applied to each element)
   */
  let map: ('a => 'b, list('a)) => list('b);
  /*
    iter(f, list) calls [f] on each element in [list]. Since [f] returns
    [unit], there is nothing to return
   */
  let iter: ('a => unit, list('a)) => unit;
  /*
    filter(f, list) runs [f] on each element in [list] and returns a new list
    consisting of all elements [f] returned [true] for
   */
  let filter: ('a => bool, list('a)) => list('a);
} = {
  let map = (f, lst) => List.fold_left((res, current) => res @ [f(current)], [], lst);
  let iter = (f, lst) => List.fold_left((_, current) => {
    f(current)
    switch current {
    | _ => ()
    };
  }, (), lst);
  let filter = (f, lst) => List.fold_left((res, current) => {
    let result = f(current);
    switch result {
    | true => res @ [current]
    | false => res
    };
  }, [], lst);
};


let acc = ref(0);

MyList.iter(
  x =>
    if (x > acc^) {
      acc := x;
    },
  [1, 8, 5, 2, 7, 3],
);

Test.runAll([
  (MyList.map(x => 2 * x, [1, 2, 3, 4]) == [2, 4, 6, 8], "MyList.map"),
  (acc^ == 8, "MyList.iter"),
  (
    MyList.filter(x => x mod 2 == 0, [1, 3, 7, 8, 9, 2]) == [8, 2],
    "MyList.filter",
  ),
]);

// 22-records
let () = print_endline("\n22-records");

type person = {
  age: int,
  firstName: string,
  lastName: string,
  numberOfCars: int,
};

let modifyPerson = (person: person) => {
  switch person.firstName {
  | "Jan" => { ...person, age: 30 }
  | _ => { ...person, numberOfCars: person.numberOfCars + 6 }
  };
};

module ForTesting = {
  let test_ex1: person = {
    firstName: "Jan",
    lastName: "Saffer",
    age: 55,
    numberOfCars: 0,
  };
  let test_ex1': person = {...test_ex1, age: 30};
  let test_ex2: person = {
    firstName: "Hugo",
    lastName: "Heuzard",
    age: 4,
    numberOfCars: 55,
  };
  let test_ex2': person = {...test_ex2, numberOfCars: 61};
};

Test.runAll([
  (
    modifyPerson(ForTesting.test_ex1) == ForTesting.test_ex1',
    "modifyPerson",
  ),
  (
    modifyPerson(ForTesting.test_ex2) == ForTesting.test_ex2',
    "modifyPerson",
  ),
]);


// 23-mutable_records
let () = print_endline("\n23-mutable_records");

type color =
  | Red
  | Yellow
  | Green;

type stoplight = {
  location: string,
  mutable color
};

let advanceColor = stoplight => {
  switch stoplight.color {
  | Red => { stoplight.color = Green }
  | Yellow => { stoplight.color = Red }
  | Green => { stoplight.color = Yellow }
  };
};

module ForTestingMutation = {
  let test_ex_red: stoplight = {location: "", color: Red};
  let test_ex_red': stoplight = {...test_ex_red, color: Green};
  let test_ex_yellow: stoplight = {location: "", color: Yellow};
  let test_ex_yellow': stoplight = {...test_ex_red, color: Red};
  let test_ex_green: stoplight = {location: "", color: Green};
  let test_ex_green': stoplight = {...test_ex_red, color: Yellow};
};

advanceColor(ForTestingMutation.test_ex_red);

advanceColor(ForTestingMutation.test_ex_yellow);

advanceColor(ForTestingMutation.test_ex_green);

Test.runAll([
  (ForTestingMutation.test_ex_red == ForTestingMutation.test_ex_red', "advance color"),
  (ForTestingMutation.test_ex_yellow == ForTestingMutation.test_ex_yellow', "advance color"),
  (ForTestingMutation.test_ex_green == ForTestingMutation.test_ex_green', "advance color"),
]);

// 24-refs
let () = print_endline("\n24-refs");

let minAndMax = lst => {
  assert (List.length(lst) > 0);

  let minimum = ref(List.nth(lst, 0));
  let maximum = ref(List.nth(lst, 0));

  List.iter((elem) => {
    minimum := sSmallest(minimum^, elem);
    maximum := sLargest(maximum^, elem);
  }, lst);

  (minimum^, maximum^);
};

Test.runAll([
  (minAndMax([5, 9, 2, 4, 3]) == (2, 9), "min and max"),
  (minAndMax([11, 15, 7, 34]) == (7, 34), "min and max"),
]);