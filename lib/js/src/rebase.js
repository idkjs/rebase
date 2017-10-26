'use strict';

var Rebase__list       = require("./rebase__list.js");
var Rebase__array      = require("./rebase__array.js");
var Rebase__flags      = require("./rebase__flags.js");
var Rebase__option     = require("./rebase__option.js");
var Rebase__result     = require("./rebase__result.js");
var Rebase__string     = require("./rebase__string.js");
var Rebase__exceptions = require("./rebase__exceptions.js");

var Result = /* module */[
  /* unwrapUnsafely */Rebase__result.unwrapUnsafely,
  /* isOk */Rebase__result.isOk,
  /* isError */Rebase__result.isError,
  /* catch */Rebase__result.$$catch,
  /* may */Rebase__result.may,
  /* or_ */Rebase__result.or_,
  /* getOr */Rebase__result.getOr,
  /* map */Rebase__result.map,
  /* mapOr */Rebase__result.mapOr,
  /* mapOrElse */Rebase__result.mapOrElse,
  /* andThen */Rebase__result.andThen,
  /* fromOption */Rebase__result.fromOption
];

var $$String = /* module */[/* isEmpty */Rebase__string.isEmpty];

var Flags = /* module */[
  /* toInt */Rebase__flags.toInt,
  /* make */Rebase__flags.make,
  /* many */Rebase__flags.many
];

function Array_000(prim, prim$1, prim$2) {
  return prim$2.reduce(prim, prim$1);
}

function Array_001(prim, prim$1, prim$2) {
  return prim$2.reduceRight(prim, prim$1);
}

function Array_002(prim, prim$1) {
  return prim$1.map(prim);
}

function Array_008(prim, prim$1) {
  prim$1.forEach(prim);
  return /* () */0;
}

function Array_012(prim) {
  return prim.length;
}

function Array_018(prim, prim$1) {
  prim$1.fill(prim);
  return /* () */0;
}

function Array_019(prim, prim$1) {
  return prim$1.concat(prim);
}

function Array_020(prim, prim$1, prim$2) {
  return prim$2.slice(prim, prim$1);
}

function Array_021(prim) {
  return prim.slice();
}

function Array_022(prim, prim$1) {
  return prim$1.mapWithIndex(prim);
}

var $$Array = [
  Array_000,
  Array_001,
  Array_002,
  Rebase__array.apply,
  Rebase__array.from,
  Rebase__array.flatMap,
  Rebase__array.forAll,
  Rebase__array.find,
  Array_008,
  Rebase__array.exists,
  Rebase__array.filter,
  Rebase__array.make,
  Array_012,
  Rebase__array.get,
  Rebase__array.getOrRaise,
  Rebase__array.setOrRaise,
  Rebase__array.unsafeGetUnchecked,
  Rebase__array.unsafeSetUnchecked,
  Array_018,
  Array_019,
  Array_020,
  Array_021,
  Array_022
];

var List = [
  Rebase__list.reduce,
  Rebase__list.reduceRight,
  Rebase__list.map,
  Rebase__list.apply,
  Rebase__list.from,
  Rebase__list.flatMap,
  Rebase__list.forAll,
  Rebase__list.find,
  Rebase__list.forEach,
  Rebase__list.exists,
  Rebase__list.filter,
  Rebase__list.head,
  Rebase__list.tail,
  Rebase__list.length,
  Rebase__list.reverse,
  Rebase__list.toArray
];

var Option = [
  Rebase__option.reduce,
  Rebase__option.reduceRight,
  Rebase__option.map,
  Rebase__option.apply,
  Rebase__option.from,
  Rebase__option.flatMap,
  Rebase__option.forAll,
  Rebase__option.find,
  Rebase__option.forEach,
  Rebase__option.exists,
  Rebase__option.filter
];

var InvalidArgument = Rebase__exceptions.InvalidArgument;

var IndexOutOfBounds = Rebase__exceptions.IndexOutOfBounds;

exports.$$Array          = $$Array;
exports.List             = List;
exports.Option           = Option;
exports.Result           = Result;
exports.$$String         = $$String;
exports.Flags            = Flags;
exports.InvalidArgument  = InvalidArgument;
exports.IndexOutOfBounds = IndexOutOfBounds;
/* No side effect */