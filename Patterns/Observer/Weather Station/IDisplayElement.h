#ifndef _IDISPLAY_ELEMENT_H
#define _IDISPLAY_ELEMENT_H

class IDisplayElement {
public:
	virtual void Display() = 0;
	virtual ~IDisplayElement() = default;

};


#endif // !_IDISPLAY_ELEMENT_H