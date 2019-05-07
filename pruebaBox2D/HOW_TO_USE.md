# HOW TO USE

1. Copy TallerTest in the tests directory
    ```shell
    cp TallerTest.h ../Box2D/Testbed/Tests/ # <box2D>/Box2D/Testbed/Tests
    ```
2. Modify the tests entries list (add two lines)
    ```shell
    vim ../Box2D/Testbed/Tests/TestEntries.cpp
    ```

    ```c
    ...
    #include "TallerTest.h"
    ...
    {"Taller Test", TallerTest::Create },
    ...
    ```
3. Compile the TestBed
    ```shell
    cd ../Box2D/ # <box2D>/
    make -C Build Testbed
    ```
4. Execute the Testbed
    ```shell
    cd Testbed/ # <box2D>/Testbed
    ../Build/bin/x86_64/Debug/Testbed
    ```
