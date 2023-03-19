#include <App.h>
#include <psp2/kernel/processmgr.h>
using namespace std;
using namespace aw;
int main(int argc, char **argv) {
  try {
    if (APP.init(argc, argv)) {
      APP.loop();
      APP.terminate();
    }
    sceKernelExitProcess(0);
    return 0;
  } catch (const exception &err) {
    printf("An exception occured: %s", err.what());
  }
  sceKernelExitProcess(0);
}