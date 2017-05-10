#include "circle.hpp"



Circle::Circle(float const& r, Vec2 const& cntr, Color const& clr):
	r_(r),
	cntr_(cntr),
	clr_(clr)
	{}


//getter
float Circle::getradius() const
{
	return(r_);
}

Vec2 Circle::getcntr() const
{
	return(cntr_);
}
	
//memberfunktionen
float Circle::umfang() const
{
	return(M_PI*r_);
}


void Circle::draw(Window const& w, Color const& clr)
{
	float stufen=48.0f;
	Mat2 winkel=rotate((float)(2.0f*M_PI/stufen));
	Vec2 alt{r_,0.0f};
	Vec2 neu{alt};

	for(int i; i<=stufen; i++)
	{
		/*
		//neuer punkt ist alter punkt um winkel verschoben
		Vec2 neu=winkel*alt;
		//linien zeichnen
		w.draw_line(
			cntr_.x_+alt.x_,
			cntr_.y_+alt.y_,
			cntr_.x_+neu.x_,
			cntr_.y_+neu.y_, 
			clr.r_, 
			clr.g_, 
			clr.b_);
		//alten punkt nachruecken
		alt=winkel*alt;
		*/
		alt+=cntr_;
		neu=winkel*neu;
		neu+=cntr_;
		w.draw_line(
			alt.x_,
			alt.y_,
			neu.x_,
			neu.y_,
			clr.r_, 
			clr.g_, 
			clr.b_
			);
		neu-=cntr_;
		alt=neu;
	}	

}


void Circle::draw(Window const& w)
{
	draw(w, clr_);
}


	



