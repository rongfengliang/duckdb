
#include "catch.hpp"
#include "test_helpers.hpp"

using namespace duckdb;
using namespace std;

TEST_CASE("Test scalar queries [C]", "[scalarquery]") {
	unique_ptr<DuckDBResult> result;
	DuckDB db(nullptr);
	DuckDBConnection con(db);

	result = con.Query("SELECT 42");
	REQUIRE(CHECK_COLUMN(result, 0, {42}));

	result = con.Query("SELECT 42 + 1");
	REQUIRE(CHECK_COLUMN(result, 0, {43}));

	result = con.Query("SELECT 2 * (42 + 1), 35 - 2");
	REQUIRE(CHECK_COLUMN(result, 0, {86}));
	REQUIRE(CHECK_COLUMN(result, 1, {33}));

	result = con.Query("SELECT 'hello'");
	REQUIRE(CHECK_COLUMN(result, 0, {"hello"}));

	result = con.Query("SELECT cast('3' AS INTEGER)");
	REQUIRE(CHECK_COLUMN(result, 0, {3}));

	result = con.Query("SELECT cast(3 AS VARCHAR)");
	REQUIRE(CHECK_COLUMN(result, 0, {"3"}));

	result = con.Query("SELECT CASE WHEN 43 > 33 THEN 43 ELSE 33 END;");
	REQUIRE(CHECK_COLUMN(result, 0, {43}));
}