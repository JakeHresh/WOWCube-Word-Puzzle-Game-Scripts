//Implementation of Xorshift random number generator

// Initial value
new RND_xorshift32_state[.a] = -2147483648//2147483647// Lowest Value -2147483648;
new RND_xorshift_seed;

// The state word must be initialized to non-zero 
RND_xorshift32()
{
	/* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
	new x = RND_xorshift32_state.a;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
    RND_xorshift32_state.a = x;
	return x;
}

// Randomize function
RND_randomize(min, max) 
{
    RND_xorshift_seed = RND_xorshift32();
    return (min + (RND_xorshift_seed % (max - min)));
}