#include "message.h"
#include <cstring>
#include <vector>
#include <cstdint>
using namespace std;
/*void serialize(const Message& input, char* buffer) {
    int offset = 0;
    memcpy(buffer + offset, input.mesaj, sizeof(input.mesaj)); offset += sizeof(input.mesaj);
    memcpy(buffer + offset, input.isim, sizeof(input.isim)); offset += sizeof(input.isim);
    memcpy(buffer + offset, input.soyisim, sizeof(input.soyisim)); offset += sizeof(input.soyisim);
    memcpy(buffer + offset, &input.yas, sizeof(input.yas)); offset += sizeof(input.yas);
    memcpy(buffer + offset, &input.boy, sizeof(input.boy)); offset += sizeof(input.boy);
    memcpy(buffer + offset, &input.aktif, sizeof(input.aktif));
}

void deserialize(const char* buffer, Message& output) {
    int offset = 0;
    memcpy(output.mesaj, buffer + offset, sizeof(output.mesaj)); offset += sizeof(output.mesaj);
    memcpy(output.isim, buffer + offset, sizeof(output.isim)); offset += sizeof(output.isim);
    memcpy(output.soyisim, buffer + offset, sizeof(output.soyisim)); offset += sizeof(output.soyisim);
    memcpy(&output.yas, buffer + offset, sizeof(output.yas)); offset += sizeof(output.yas);
    memcpy(&output.boy, buffer + offset, sizeof(output.boy)); offset += sizeof(output.boy);
    memcpy(&output.aktif, buffer + offset, sizeof(output.aktif));
}
*/




