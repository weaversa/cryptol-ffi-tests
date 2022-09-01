SHELL = /bin/bash
CFLAGS = -O3 -Wall -Wextra -Werror -lcrypto

.PHONY: clean

ifeq ($(shell uname),Darwin)

SO = shatest.dylib
TEST_OUT_EXT = .stdout.darwin

$(SO): shatest.c
	$(CC) $(CFLAGS) -dynamiclib $< -o $@

else

SO = shatest.so
TEST_OUT_EXT = .stdout

$(SO): shatest.c
	$(CC) $(CFLAGS) -fPIC -shared $< -o $@

endif

perf-test: $(SO)
	time cryptol -b shatest.icry

clean:
	rm $(SO)
