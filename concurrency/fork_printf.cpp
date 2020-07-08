#include <cstdio>
#include <sys/poll.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 4; i++) {
        printf("%d\n", i);
        fork();
    }
    fflush(stdout);
    poll(nullptr, 0, 10);
}

// Local Variables:
// rmsbolt-command: "clang -std=c++17 -O3"
// rmsbolt-disassemble: nil
// End:
