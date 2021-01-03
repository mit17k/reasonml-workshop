// 02-basic_types
let intAverage: (int, int) => int;
let floatAverage: (float, float) => float;
let getName: (string, string) => string;

// 03-define_functions
let plus: (int, int) => int;
let times: (int, int) => int;
let minus: (int, int) => int;
let divide: (int, int) => int;

// 04-call_functions
let average: (int, int) => int;

// 05-twice
let add1: int=> int;
let square: int => int;
let twice: ('a => 'a, 'a) => 'a;
let add2: int => int;
let raiseToTheFourth: int => int;

// 06-pattern-matching
let nonZero: int => bool;

// 07-simple_recursion
let factorial: int => int;

// 08-list_intro
let lSum: list(int) => int;

// 09-list_range
let range: (int, int) => list(int);

// 10-list_product
let lProduct: list(int) => int;

// 11-sum_product
let simplerSum: list(int) => int;
let simplerProduct: list(int) => int;

// 12-list_min
let largest: list(float) => float;
let smallest: list(float) => float;

// 13-largest_smallest
let simplerLargest: list(float) => float;
let simplerSmallest: list(float) => float;

// 14-variants
type cardValue;
let cardValueToScore: cardValue => int;

// 15-tuples
type pair('a);
type coordinate = pair(int);

let addTuples: (coordinate, coordinate) => coordinate;
let firstTuple: pair('a) => 'a;
let secondTuple: pair('a) => 'a;

// 16-labelled_arguments
let modulo: (~dividend: int, ~divisor: int) => int;

// 17-options
type option('a) =
  | None
  | Some('a);

let safeDivide: (~dividend: int, ~divisor: int) => option(int);

// 18-anonymous_functions
let applyIfNonzero: (int => int, int) => int;

// 19-list_operations
let myNewInts: list(int) => list(int);
let numEvenInts: list(int) => int;

// 22-records
type person;
let modifyPerson: person => person;

// 23-mutable_records
type stoplight;
let advanceColor: stoplight => unit;

// 24-refs
let minAndMax: list(int) => (int, int);