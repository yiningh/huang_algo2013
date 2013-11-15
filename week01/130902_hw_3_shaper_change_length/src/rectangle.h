#ifndef RECTANGLE_H
#define RECTANGLE_H


class rectangle
{
    public:
        rectangle();
        virtual ~rectangle();

        void draw();
		void interpolateByPct(float myPct);

		ofPoint		pos;
		ofPoint		posa;
		ofPoint		posb;
		float		pct;	// what pct are we between "a" and "b"
		float		shaper;
		float       mySize;

    protected:
    private:
};

#endif // RECTANGLE_H
