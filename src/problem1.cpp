#include <array>
#include <bitset>
#include <cstring>
#include <iostream>
#include <optional>
#include <vector>

using Message = std::array<std::optional<uint16_t>, 8>;

template <typename Iter, typename F>
void print_iterable(const Iter &iter, F formatter, const char *delimiter) {
  bool first = true;
  std::cout << "[";
  for (auto &v : iter) {
    if (!first)
      std::cout << delimiter;
    std::cout << formatter(v);
    first = false;
  }
  std::cout << "]" << std::endl;
}

void print(const std::vector<uint8_t> &data) {
  print_iterable(
      data, [](auto v) { return std::bitset<8>(v); }, " ");
}

void print(const Message &msg) {
  print_iterable(
      msg, [](auto v) { return v ? std::to_string(*v) : std::string("null"); },
      ", ");
}

std::vector<uint8_t> encode(const Message &msg) {
  // write your encoder function here
  std::vector<uint8_t> out;
  uint8_t s = 0;
  for(size_t i = 0; i < msg.size(); ++i){
    if(msg[i]!=NULL){
      s = s|(1<<(7-i));
    }
  }
  out.push_back(s);
  for (size_t i = 0; i < msg.size(); ++i) {
        if (msg[i]!=NULL) {
            uint16_t value = msg[i].value();
            for (int j = sizeof(uint16_t) - 1; j >= 0; --j) {
                out.push_back((value >> (8 * j)) & 0xFF);
            }
        }
    }
  //memcpy(out.data(), &msg, sizeof(msg));
  return out;
}

bool decode(Message &msg, const std::vector<uint8_t> &data) {
  // write your decoder function here
  if (sizeof(msg) != data.size())
  {
  return false;
  }

  uint8_t firstByte = data[0];
    for (size_t i = 0; i < 8; ++i) {
        if (firstByte & (1 << (7 - i))) {
            uint16_t value = (data[i * 2 + 1] << 8) | data[i * 2 + 2];
            msg[i] = value;
        }
    }
  return true;
}

void test() {
  // put your test cases here
  Message msg = {1,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
  print(msg);
  std::vector<uint8_t> out = encode(msg);
  print(out);
  decode(msg, out);
  print(msg);
}

int main() {
  test();
  return 0;
}