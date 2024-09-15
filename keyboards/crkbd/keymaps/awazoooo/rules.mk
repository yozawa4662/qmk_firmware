RGBLIGHT_ENABLE = no
OLED_ENABLE = yes

# If you want to change the display of OLED, you need to change here
#SRC += ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        ./lib/mode_icon_reader.c \
        ./lib/host_led_state_reader.c \
        ./lib/timelogger.c \

SRC += ./keymaps/awazoooo/lib/keylogger.c \
       ./keymaps/awazoooo/lib/timelogger.c \
       ./keymaps/awazoooo/lib/layer_state_reader.c

TAP_DANCE_ENABLE = yes
