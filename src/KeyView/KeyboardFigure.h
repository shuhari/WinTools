#pragma once

class KeyboardFigure {
public:
	KeyboardFigure();
	~KeyboardFigure();

	CSize size();
	void draw(CDCHandle dc);
};

