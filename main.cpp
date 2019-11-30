#include <iostream>
#include <ao/ao.h>
#include <mpg123.h>

const int BITS{8};

using namespace std;

int main() {
    mpg123_handle *handle;
    unsigned char *buffer;
    size_t buffer_size, done;
    int err;

    int driver;
    ao_device *device;
    ao_sample_format sampleFormat;
    int channel, encoding;
    long rate;

    ao_initialize();
    driver = ao_default_driver_id();
    mpg123_init();

    handle = mpg123_new(nullptr, &err);
    buffer_size = mpg123_outblock(handle);

    buffer = new unsigned char[buffer_size];
    mpg123_open(handle, "/home/one/Music/Hero_Memories.mp3");
    mpg123_getformat(handle, &rate, &channel, &encoding);

    sampleFormat.bits = mpg123_encsize(encoding) * BITS;
    sampleFormat.rate = rate;
    sampleFormat.channels = channel;
    sampleFormat.byte_format = AO_FMT_NATIVE;
    sampleFormat.matrix = nullptr;
    device = ao_open_live(driver, &sampleFormat, nullptr);

    cout << "Driver id: " << driver << '\t';
    cout << "Device id: " << device << endl;
    cout << "Rate: " << rate << '\t' << "Channel: " << channel << '\t' << "Encoding: " << encoding << endl;
    cout << "Error No: " << errno << endl;

    while (mpg123_read(handle, buffer, buffer_size, &done) == MPG123_OK)
        ao_play(device, reinterpret_cast<char *>(buffer), done);

    delete (buffer);

    ao_close(device);
    mpg123_close(handle);
    mpg123_delete(handle);
    mpg123_exit();
    ao_shutdown();

    return 0;
}