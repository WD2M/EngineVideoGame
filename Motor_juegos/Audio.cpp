#include "Audio.h"
#include "string"
#include <locale>
#include <codecvt>

void Audio::initAudio(string audio)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wide_audio = converter.from_bytes(audio);

    PlaySound(wide_audio.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void Audio::stopAudio(string audio)
{
}
