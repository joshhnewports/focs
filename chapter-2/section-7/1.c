int square(int n);

main()
{
}

int square(int n)
{
    if (n <= 1)
	return 1;
    else
	return square(n-1) + 2*n - 1;
}
