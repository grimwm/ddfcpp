#include <cstdio>
#include <cerrno>

#include <unistd.h>

#include "DriverProxy.hpp"
#include "KeyboardDriver.hpp"
#include "Service.hpp"

using namespace SymbolX;

static char const NAME[] = "KeyboardDriverProxyTests";
static const unsigned BUFFER_SIZE = 1024;

int main()
{
  FILE *ofile = fopen("/tmp/KeyboardDriverProxyTests.out", "w");

  if (!ofile) {
    Service::Panic((char *)NAME, (char *)strerror(errno), errno);
    return errno;
  }

  IDriver *proxy = new DriverProxy();

  int ret = proxy->Open("MockKeyboardDriver", 123);
  fprintf(ofile, "Open returned: %d\n", ret);

  ret = proxy->Close();
  fprintf(ofile, "Close returned: %d\n", ret);

  unsigned char buffer[BUFFER_SIZE];
  ret = proxy->Read(0, BUFFER_SIZE, buffer);
  fprintf(ofile, "Read returned: %d\n", ret);
  fprintf(ofile, "Read data: ");
  for (unsigned i = 0; i < BUFFER_SIZE; ++i) {
    fprintf(ofile, "0x%X ", buffer[i]);
  }
  fprintf(ofile, "\n");

  ret = proxy->IOControl(KEYBOARD_IOCTL_CLEAR_DATA, NULL);
  fprintf(ofile, "IOControl returned: %d\n", ret);

  ret = proxy->Gather(0, 0, NULL);
  fprintf(ofile, "Gather returned: %d\n", ret);

  ret = proxy->Scatter(0, 0, NULL);
  fprintf(ofile, "Scatter returned: %d\n", ret);

  ret = proxy->Cancel();
  fprintf(ofile, "Cancel returned: %d\n", ret);

  buffer[0] = static_cast<unsigned char>(0);

  // Wait for service to be terminated.
  while (1) {
    // Here we will continue to ask driver to flip keyboard activity for us.
    ret = proxy->Write(0, 1, buffer);
    fprintf(ofile, "Write returned: %d\n", ret);
    buffer[0] = !buffer[0];
    if (fflush(ofile) < 0) {
      Service::Panic((char *)NAME, (char *)strerror(errno), errno);
      return errno;
    }
    sleep(900);
  }

  if (fclose(ofile) < 0) {
    Service::Panic((char *)NAME, (char *)strerror(errno), errno);
    return errno;
  }

  delete proxy;

  return 0;
}
