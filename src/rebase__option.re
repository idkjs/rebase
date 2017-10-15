open Rebase__result__type;

type t 'a = option 'a;

let from x =>
  Some x;

let unwrapUnsafely =
  fun
  | Some v => v
  | None => raise (Invalid_argument "unwrapUnsafely called on None");

let isSome =
  fun
  | Some _ => true
  | None => false;

let isNone =
  fun
  | Some _ => false
  | None => true;

let may f =>
  fun
  | Some v => f v
  | None => ();

let or_ other =>
  fun
  | Some _ as self => self
  | None => other;

let getOr other =>
  fun
  | Some v => v
  | None => other;

let map f =>
  fun
  | Some v => Some (f v)
  | None => None;

let mapOr f other =>
  fun
  | Some v => f v
  | None => other;

let mapOrElse f g =>
  fun
  | Some v => f v
  | None => g ();

let andThen f =>
  fun
  | Some v => f v
  | None => None;

let exists predicate =>
  fun
  | Some v => predicate v
  | None => false;

let forAll predicate =>
  fun
  | Some v => predicate v
  | None => true;

let filter predicate =>
  fun
  | Some v as self when predicate v => self
  | _ => None;

let fromResult =
  fun
  | Ok v => Some v
  | Error _ => None;


let forEach f =>
  fun
  | None => ()
  | Some x => f x;

let find p =>
  fun
  | Some x when p x => Some x
  | _ => None;

let findOrRaise p =>
  fun
  | Some x when p x => x
  | _ => raise Not_found;

let flatMap f =>
  fun
  | None => None
  | Some x => f x;

let apply f a =>
  switch f {
  | None => None
  | Some f => map f a
  };

let reduce f acc =>
  fun
  | None => acc
  | Some x => f acc x;

  let reduceRight f acc =>
  fun
  | None => acc
  | Some x => f acc x;