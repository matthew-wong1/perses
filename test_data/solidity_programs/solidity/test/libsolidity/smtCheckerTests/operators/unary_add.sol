pragma experimental SMTChecker;

contract C
{
	function f() public pure {
		uint x = 2;
		uint a = ++x;
		assert(x == 3);
		assert(a == 3);
		uint b = x++;
		assert(x == 4);
		// Should fail.
		assert(b < 3);
	}
}
// ----
// Warning 6328: (194-207): CHC: Assertion violation happens here.\nCounterexample:\n\nx = 4\na = 3\nb = 3\n\nTransaction trace:\nC.constructor()\nC.f()
