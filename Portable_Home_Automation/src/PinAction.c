
void SetFireAngle()
{
    if(Actiondata > 9) Actiondata = 9;
    Fireangle = (78*((Actiondata*100)/10));
}

void ManualControl()
{
	if(Actiondata <  9) Actiondata = 9;
	else{				Actiondata = 1;}
	SetFireAngle();
}

void ZeroCrossing()
{
    delayMicroseconds(Fireangle);
    digitalWrite(LED, LOW);     //change to HIGH
    delayMicroseconds(10);
    digitalWrite(LED, HIGH);
}