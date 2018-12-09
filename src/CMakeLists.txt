FILE(GLOB sourcefiles
        ./*cpp
        ./*h)

ADD_LIBRARY(SeqLock STATIC ${sourcefiles})