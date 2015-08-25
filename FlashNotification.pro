APP_NAME = FlashNotification

CONFIG += qt warn_on cascades10

QT += declarative
CONFIG += qt warn_on debug_and_release cascades mobility
MOBILITY += sensors

LIBS += -lbb
LIBS += -lbbdata
LIBS += -lbbsystem
LIBS += -lbbdevice
LIBS += -lcamapi

include(config.pri)
