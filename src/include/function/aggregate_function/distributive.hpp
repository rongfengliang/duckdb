//===----------------------------------------------------------------------===//
//                         DuckDB
//
// function/aggregate_function/distributive.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "common/types/data_chunk.hpp"
#include "function/function.hpp"

namespace duckdb {

//! The type used for aggregate functions
typedef void (*aggregate_function_t)(Vector inputs[], index_t input_count, Vector &result);
typedef void (*aggregate__simple_function_t)(Vector inputs[], index_t input_count, Value &result);

static SQLType get_same_return_type(vector<SQLType> &arguments) {
	assert(arguments.size() == 1);
	return arguments[0];
}

static SQLType get_bigint_return_type(vector<SQLType> &arguments) {
	return SQLTypeId::BIGINT;
}

void count_function( Vector inputs[], index_t input_count, Vector &result );
void count_simple_function( Vector inputs[], index_t input_count, Value &result );

class CountFunction {
public:
	static const char*GetName() {
		return "count";
	}

	static aggregate_function_t GetFunction() {
		return count_function;
	}

	static aggregate__simple_function_t GetSimpleFunction() {
		return count_simple_function;
	}

	static get_return_type_function_t GetReturnTypeFunction() {
		return get_bigint_return_type;
	}

};

void max_function( Vector inputs[], index_t input_count, Vector &result );
void max_simple_function( Vector inputs[], index_t input_count, Value &result );

class MaxFunction {
public:
	static const char*GetName() {
		return "max";
	}

	static aggregate_function_t GetFunction() {
		return max_function;
	}

	static aggregate__simple_function_t GetSimpleFunction() {
		return max_simple_function;
	}

	static get_return_type_function_t GetReturnTypeFunction() {
		return get_same_return_type;
	}

};

void min_function( Vector inputs[], index_t input_count, Vector &result );
void min_simple_function( Vector inputs[], index_t input_count, Value &result );

class MinFunction {
public:
	static const char*GetName() {
		return "min";
	}

	static aggregate_function_t GetFunction() {
		return min_function;
	}

	static aggregate__simple_function_t GetSimpleFunction() {
		return min_simple_function;
	}

	static get_return_type_function_t GetReturnTypeFunction() {
		return get_same_return_type;
	}

};

void sum_function( Vector inputs[], index_t input_count, Vector &result );
void sum_simple_function( Vector inputs[], index_t input_count, Value &result );
SQLType sum_get_return_type(vector<SQLType> &arguments);

class SumFunction {
public:
	static const char*GetName() {
		return "sum";
	}

	static aggregate_function_t GetFunction() {
		return sum_function;
	}

	static aggregate__simple_function_t GetSimpleFunction() {
		return sum_simple_function;
	}

	static get_return_type_function_t GetReturnTypeFunction() {
		return sum_get_return_type;
	}

};

} // namespace duckdb
