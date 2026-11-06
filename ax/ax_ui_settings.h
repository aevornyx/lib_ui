// Часть AxGram для Desktop. Файл изменён.
//
// Основано на исходном коде AyuGram for Desktop.
// Copyright @Radolyn, 2026
//
// Распространяется по GNU GPL v3 — см. LICENSE и NOTICE.md.
#pragma once

namespace AxUiSettings {

inline constexpr int kMaxAvatarCorners = 23;

void setMonoFont(QString newFont);
QString getMonoFont();

void setWideMultiplier(double val);

bool isWideMultiplied();
int getWideMultiplied(int width, double mult);

void setMaterialSwitches(bool val);
bool isMaterialSwitches();

void setAnimatedIconsEnabled(bool enabled);
void setAnimatedIconsPolicy(bool (*policy)());
[[nodiscard]] bool animatedIconsEnabled();

void setAvatarCorners(int val);
int getAvatarCorners();

}
