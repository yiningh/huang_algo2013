#ifndef RECTANGLE_H
#define RECTANGLE_H


class rectangle
{
    public:
        rectangle();
        virtual ~rectangle();

        void	draw();
		void	xenoToPoint(float catchX, float catchY);

		ofPoint		pos;
		float		catchUpSpeed;		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
		int myColor;

    protected:
    private:
};

#endif // RECTANGLE_H
