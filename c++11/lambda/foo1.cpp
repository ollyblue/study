
#include <string>
#include <vector>

using namespace std;

void test_1();

int main(int argc, const char* argv[])
{
	test_1();

	return 0;
}

void test_1()
{
	auto f = [](int x, int y) -> int { return x + y }

	auto z = f(1,2);

	printf("result of z:%d\n", z);
}

