#include <stdio.h>
#include <string.h>
#include <sys/queue.h>
#include <malloc.h>


int main(int argc, char const *argv[])
{
	struct foo {
		TAILQ_ENTRY(foo) tailq;
		int datum;
	};

	TAILQ_HEAD(fooq, foo);

	struct fooq q;
	TAILQ_INIT(&q);


	struct foo *item1 = malloc(sizeof(struct foo));
	item1->datum = 10;
	TAILQ_INSERT_TAIL(&q, item1, tailq);


	struct foo *item2 = malloc(sizeof(struct foo));
	item2->datum = 20;
	TAILQ_INSERT_TAIL(&q, item2, tailq);



	struct foo *p;
	TAILQ_FOREACH(p, &q, tailq) {
		printf(" %d", p->datum);
	}
	puts("");


	return 0;
}
