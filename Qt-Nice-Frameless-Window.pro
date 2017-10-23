TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS += framelesswindow \
    exampleforwindows \
    examplesimplest \
    exampleformac

exampleforwindows.depends = framelesswindow
examplesimplest.depends = framelesswindow
exampleformac.depends = framelesswindow
