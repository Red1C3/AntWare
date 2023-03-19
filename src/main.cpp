#include <App.h>
#ifdef __VITA__
#include <psp2/kernel/processmgr.h>
#endif


using namespace std;
using namespace aw;
int main(int argc, char **argv) {
  try {
    if (APP.init(argc, argv)) {
      APP.loop();
    }
#ifdef __VITA__
    sceKernelExitProcess(0);
#endif
    return 0;
  } catch (const exception &err) {
    printf("An exception occured: %s", err.what());
  }
#ifdef __VITA__
  sceKernelExitProcess(0);
#endif
}