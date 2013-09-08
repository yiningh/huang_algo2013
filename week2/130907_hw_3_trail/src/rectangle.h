#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H


class rectangle
{
    public:
        rectangle();
        void	draw();
		void	xenoToPoint(float catchX, float catchY);

		ofVec2f		pos;
		float		catchUpSpeed;		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
		int myColor;
};

#endif // RECTANGLE_H
