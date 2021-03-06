/*
 *  maximilian
 *  platform independent synthesis library using portaudio or rtaudio
 *
 *  Created by Mick Grierson on 29/12/2009.
 *  Copyright 2009 Mick Grierson & Strangeloop Limited. All rights reserved.
 *	Thanks to the Goldsmiths Creative Computing Team.
 *	Special thanks to Arturo Castro for the PortAudio implementation.
 * 
 *	Permission is hereby granted, free of charge, to any person
 *	obtaining a copy of this software and associated documentation
 *	files (the "Software"), to deal in the Software without
 *	restriction, including without limitation the rights to use,
 *	copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the
 *	Software is furnished to do so, subject to the following
 *	conditions:
 *	
 *	The above copyright notice and this permission notice shall be
 *	included in all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,	
 *	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *	OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *	HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *	WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *	OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef _FFT
#define _FFT

#ifndef M_PI
#define	M_PI		3.14159265358979323846  /* pi */
#endif

#ifdef __APPLE_CC__
#include <Accelerate/Accelerate.h>
#endif



class fft {
	
public:
	
	fft(SI4 fftSize);
	~fft();	
	
	SI4 n; //fftSize
	SI4 half; //halfFFTSize
	
	float			*in_real, *out_real, *in_img, *out_img;
    
#ifdef __APPLE_CC__
	SI4 log2n; //log2(n);
    FFTSetup        setupReal;
    COMPLEX_SPLIT   A;
	float *polar;
	void powerSpectrum_vdsp(SI4 start, float *data, float *window, float *magnitude,float *phase);	
	void inversePowerSpectrum_vdsp(SI4 start, float *finalOut, float *window, float *magnitude,float *phase);	
	void convToDB_vdsp(float *in, float *out);
#endif
	
	/* Calculate the power spectrum */
	void powerSpectrum(SI4 start, float *data, float *window, float *magnitude, float *phase);
	/* ... the inverse */
	void inversePowerSpectrum(SI4 start, float *finalOut, float *window, float *magnitude,float *phase);	
	void convToDB(float *in, float *out);
    
	static void genWindow(SI4 whichFunction, SI4 NumSamples, float *window);
	
};


#endif	
