#include <iostream>

#include <sweep/sweep.hpp>

int main() {
  sweep::sweep device;

  device.start_scanning();

  auto speed = device.get_motor_speed();
  device.set_motor_speed(speed + 1);

  auto rate = device.get_sample_rate();

  for (auto n = 0; n < 10; ++n) {
    auto scan = device.get_scan();

    for (auto sample : scan.samples) {
      std::cout << "angle " << sample.angle << " distance " << sample.distance << " strength " << sample.signal_strength << "\n";
    }
  }
}
