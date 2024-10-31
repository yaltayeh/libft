#include <stdio.h>

typedef union test
{
	int a;
	double b;
	void *p;
} t_test;

struct test
{
	int	a;
	int	b;
};

int	op(int n1, int n2, int (*_op)())
{
	int	err;
	int	ret;
	int	(*__op)(int, int, int *);

	err = 0;
	__op = _op;
	ret = __op(n1, n2, &err);
	printf("err: %d\n", err);
	return (ret);
}

int add(int n1, int n2)
{
	return (n1 + n2);
}

int div(int n1, int n2, int *err)
{
	if (n2 == 0)
	{
		*err = 1;
		return (0);
	}
	return (n1 / n2);
}

int	main(void)
{
	int ret;

	ret = op(10, 10, add);
	printf("%d \n", ret);
	return (0);
}
