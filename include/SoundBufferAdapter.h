#pragma once

namespace aw {

class SoundBufferAdapter {
private:
  const char *path;

public:
  void loadFromFile(const char *path);
  const char *getPath();
};
} // namespace aw
