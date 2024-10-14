float on_sound[][2] = SONG(CUSTOM_TOGGLE_ON_SOUND);
float off_sound[][2] = SONG(CUSTOM_TOGGLE_OFF_SOUND);

void custom_toggle_sound(bool state) {
    if (state) {
        PLAY_SONG(on_sound);
    }
    else {
        PLAY_SONG(off_sound);
    }
}