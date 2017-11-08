type t('a) = list('a);

let head =
  fun | [] => None
      | [x, ..._] => Some(x);

let tail =
  fun | [] => None
      | [_, ...xs] => Some(xs);

let rec reverseAndAppend = (acc) =>
  fun | [] => acc
      | [x, ...xs] => reverseAndAppend([x, ...acc], xs);

let reverse = (self) =>
  reverseAndAppend([], self);

let rec filter = (predicate) =>
  fun | [] => []
      | [x, ...xs] when predicate(x) => [x, ...filter(predicate, xs)] /* NOTE: not tail-recursive */
      | [_, ...xs] => filter(predicate, xs);

let rec exists = (predicate) =>
  fun | [] => false
      | [x, ..._] when predicate(x) => true
      | [_, ...xs] => exists(predicate, xs);

let rec forEach = (f) =>
  fun | [] => ()
      | [x, ...xs] => {
        f(x);
        forEach(f, xs)
      };

let rec find = (predicate) =>
  fun | [] => None
      | [x, ..._] when predicate(x) => Some(x)
      | [_, ...xs] => find(predicate, xs);

let rec forAll = (predicate) =>
  fun | [] => true
      | [x, ...xs] when predicate(x) => forAll(predicate, xs)
      | _ => false;

let flatMap = (f, self) => {
  let rec aux = (inner, outer) =>
    switch inner {
    | [] =>
      switch outer {
      | [] => []
      | [x, ...xs] => aux(f(x), xs)
      }
    | [x, ...xs] => [x, ...aux(xs, outer)]
    };
  aux([], self)
};

let from = (x) =>
  [x];

let rec map = (f) =>
  fun | [] => []
      | [x, ...xs] => [f(x), ...map(f, xs)];

let product = (f, xs, ys) =>
  flatMap((x) => map((y) => f(x, y), ys), xs);

let apply = (fs, xs) =>
  product((f, x) => f(x), fs, xs);

let rec reduce = (f, acc) =>
  fun | [] => acc
      | [x, ...xs] => reduce(f, f(acc, x), xs);

let rec reduceRight = (f, acc) =>
  fun | [] => acc
      | [x, ...xs] => f(reduceRight(f, acc, xs), x);

let length = (self) => {
  let rec aux = (acc) =>
    fun | [] => acc
        | [_, ...xs] => aux(1, xs);
  aux(0, self)
};

let rec zip = (xs, ys) =>
  switch (xs, ys) {
  | ([], _)
  | (_, []) => []
  | ([x, ...xs], [y, ...ys]) => [(x,y), ...zip(xs, ys)]
  };

let toArray =
  fun | [] => [||]
      | [x, ...xs] as list => {
        let array = Rebase__array.make(length(list), x);
        let rec fill = (i) =>
          fun | [] => array
              | [x, ...xs] => {
                Rebase__array.unsafeSetUnchecked(i, x, array);
                fill(i + 1, xs)
              };
        fill(1, xs)
      };