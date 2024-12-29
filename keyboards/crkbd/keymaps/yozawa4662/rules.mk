RGBLIGHT_ENABLE = no
OLED_ENABLE = yes

# If you want to change the display of OLED, you need to change here
SRC += ./lib/keylogger.c \
       ./lib/timelogger.c \
       ./lib/layer_state_reader.c \
       ./lib/twpair_on_jis.c

TAP_DANCE_ENABLE = yes

KEY_OVERRIDE_ENABLE = yes
