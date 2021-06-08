#define _Explosion_

#ifdef _ずん子_

#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    float px, py, angle = 0, scale = 0.15;
    int counter = 0, interval = 20;
    const int numImgs = 8;
    int imgs[numImgs];
    for (int i = 0; i < 8; i++) {
        char filename[64];
        sprintf_s(filename, "assets\\lady\\a%d.png", i);
        imgs[i] = loadImage(filename);
    } 
    while (notQuit) {
        px = width - 400 * scale;
        py = height - 520 * scale;

        clear(31, 30, 51);

        ++counter %= numImgs * interval;
        int no = counter / interval;
        rectMode(CENTER);
        image(imgs[no], px, py, angle, scale);

        fill(230);
        textSize(30);
        text("少女歩行中...", width - 300 , height - 30);
    }
}

#endif 

#ifdef _Explosion_
#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    struct EXPLOSION {
        float px, py, angle, scale;
        int interval, counter = -1;
    };
    const int numExplosions = 30;
    struct EXPLOSION e[numExplosions];
    int triggerCount = 0;
    int triggerInterval = 10;
    
    const int numImgs = 60;
    int imgs[numImgs];
    for (int i = 0; i < 60; i++) {
        char filename[32];
        sprintf_s(filename, "assets\\explosion\\a%02d.png",i);
        imgs[i] = loadImage(filename);
    }

    while (notQuit) {
        ++triggerCount %= triggerInterval;
        if (triggerCount == 0) {
            for (int i = 0; i < numExplosions; i++) {
                if (e[i].counter == -1) {
                    e[i].px = random(width / 2 - 200, width / 2 + 200);
                    e[i].py = random(height / 2 - 100, height / 2 + 100);
                    e[i].angle = random(6.28f);
                    e[i].scale = random(5, 10);
                    e[i].interval = random(1, 3);
                    e[i].counter = 0;
                    i = numExplosions;
                }
            }
        }
        for (int i = 0; i < numExplosions; i++) {
            if (e[i].counter >= 0) {
                e[i].counter++;
                if (e[i].counter >= e[i].interval * numImgs) {
                    e[i].counter = -1;
                }
            }
        }
        clear();
        for (int i = 0; i < numExplosions; i++) {
            if (e[i].counter >= 0) {
                rectMode(CENTER);
                int no = e[i].counter / e[i].interval;
                image(imgs[no], e[i].px, e[i].py, e[i].angle, e[i].scale);
            }

        }
    }
}
#endif

















#ifdef _SAMPLE1
#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    //キャラデータ
    float px = width / 2, py = height / 2, angle = 0, scale = 1.0f;
    int counter = -1, interval = 8;
    //画像番号配列データ
    const int numImgs = 8;
    int imgs[numImgs];
    //画像読み込み
    for (int i = 0; i < numImgs; i++) {
        char filename[32];
        sprintf_s(filename, "assets\\lady\\a%d.png", i);
        imgs[i] = loadImage(filename);
    }
    //メインループ
    ShowCursor(false);
    while (notQuit) {
        int maxFrame = interval * numImgs;
        ++counter %= maxFrame;
        int no = counter / interval;
        //描画
        clear(200, 160, 200);
        rectMode(CENTER);
        image(imgs[no], px, py, angle, scale);
    }
    ShowCursor(true);
}
#endif

#ifdef _SAMPLE2
#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    //爆発データ
    struct EXPLOSION {
        float px, py, angle, scale;
        int interval, counter = -1;
    };
    const int numExplosions = 30;
    struct EXPLOSION e[numExplosions];
    int triggerCnt = 0;
    int triggerInterval = 5;
    //画像データ
    const int numImgs = 60;
    int imgs[numImgs];
    for (int i = 0; i < numImgs; i++) {
        char filename[32];
        sprintf_s(filename, "assets\\explosion\\a%02d.png", i);
        imgs[i] = loadImage(filename);
    }
    ShowCursor(false);
    while (notQuit) {
        //爆発開始
        ++triggerCnt %= triggerInterval;
        if (triggerCnt == 0) {
            for (int i = 0; i < numExplosions; i++) {
                if (e[i].counter == -1) {
                    e[i].px = random(width / 2 - 150, width / 2 + 150);
                    e[i].py = random(height / 2 - 100, height / 2 + 100);
                    e[i].angle = random(3.14f * 2);
                    e[i].scale = random(5.0f, 10.0f);
                    e[i].interval = random(1, 3);
                    e[i].counter = 0;
                    i = numExplosions;
                }
            }
        }
        //爆発進行
        for (int i = 0; i < numExplosions; i++) {
            if (e[i].counter >= 0) {
                ++e[i].counter;
                //爆発終了
                if (e[i].counter >= e[i].interval * numImgs) {
                    e[i].counter = -1;
                }
            }
        }
        //描画
        clear(60, 120, 240);
        rectMode(CENTER);
        for (int i = 0; i < numExplosions; i++) {
            if (e[i].counter >= 0) {
                int no = e[i].counter / e[i].interval;
                image(imgs[no], e[i].px, e[i].py, e[i].angle, e[i].scale);
            }
        }
    }
    ShowCursor(true);
}
#endif