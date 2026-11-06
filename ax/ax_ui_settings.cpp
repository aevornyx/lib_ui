// Часть AxGram для Desktop. Файл изменён.
//
// Основано на исходном коде AyuGram for Desktop.
// Copyright @Radolyn, 2026
//
// Распространяется по GNU GPL v3 — см. LICENSE и NOTICE.md.
#include "ax_ui_settings.h"
#include "ui/effects/animations.h"

#include <utility>

namespace AxUiSettings {

QString monoFont;
double wideMultiplier = 1.0;
bool materialSwitches;
bool animatedIcons = false;
bool (*animatedIconsPolicy)() = nullptr;
int avatarCorners = kMaxAvatarCorners;

void setMonoFont(QString newFont) {
	monoFont = std::move(newFont);
}

QString getMonoFont() {
	return monoFont;
}

void setWideMultiplier(double val) {
	wideMultiplier = val;
}

bool isWideMultiplied() {
	return abs(wideMultiplier - 1.0) > 0.01;
}

int getWideMultiplied(int width, double mult) {
	if (!isWideMultiplied()) {
		return width;
	}
	const auto res = width * (wideMultiplier * mult);
	return std::max(width, static_cast<int>(std::round(res)));
}

void setMaterialSwitches(bool val) {
	materialSwitches = val;
}

bool isMaterialSwitches() {
	return materialSwitches;
}

void setAnimatedIconsEnabled(bool enabled) {
	animatedIcons = enabled;
}

void setAnimatedIconsPolicy(bool (*policy)()) {
	animatedIconsPolicy = policy;
}

bool animatedIconsEnabled() {
	return animatedIcons
		&& !anim::Disabled()
		&& (!animatedIconsPolicy || animatedIconsPolicy());
}

void setAvatarCorners(int val) {
	avatarCorners = val;
}

int getAvatarCorners() {
	return avatarCorners;
}

}
