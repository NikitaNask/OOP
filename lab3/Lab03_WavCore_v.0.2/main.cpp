#include <iostream>

#include "wav_core.h"
#include "WavLib.h"


using namespace std;

void  main(int argc, char *argv[])
{
	cout << "************** | WavCore | **************" << endl;
	const char* input_fname = "c:\\temp2\\0.wav";
	const char* output_fname = "c:\\temp2\\out.wav";
	wav_errors_e err;
	wav_header_s header;
	WavLib mWav = new WavLib();

	err=mWav.Init(input_fname);
	if (err != WAV_OK) {
		cerr << "read_header() error: " << (int)err << endl;
		print_info(&header);
		return err;
	}

	//mObject.PrintInputFileInfo();
	//mObject.MakeToMono();
	//mObject.MakeToMono();
	//mObject.MakeReverb();
	//mObject.MakeWavFile(output_fname);
	//mObject.PrintOutputFileInfo();
	system("pause");
}

/*

    // #### Printing header.
    print_info( &header );


    // #### Reading PCM data from file.
    vector< vector<short> > chans_data;
    err = extract_data_int16( input_fname, chans_data );
    if ( err != WAV_OK ) {
        cerr << "extract_data_int16() error: " << (int)err << endl;
        return err;
    }
    cout << endl << "********************" << endl;


    // #### Make several changes to PCM data.

    // # Making signal mono from stereo.
    vector< vector<short> > edited_data;
    err = make_mono( chans_data, edited_data );
    if ( err != WAV_OK ) {
        cerr << "make_mono() error: " << (int)err << endl;
        return err;
    }

    // # Add a reverberation
    make_reverb(edited_data, header.sampleRate, 0.5, 0.6f);

    // #### Making new WAV file using edited PCM data.
    err = make_wav_file( output_fname, header.sampleRate, edited_data );
    if ( err != WAV_OK ) {
        cerr << "make_wav_file() error: " << (int)err << endl;
        print_info( &header );
        return err;
    }


    // #### Reading the file just created to check its header corectness.
    err = read_header( output_fname, &header );
    if ( err != WAV_OK ) {
        cerr << "read_header() error: " << (int)err << endl;
        print_info( &header );
        return err;
    }
    print_info( &header );

	system("pause");
    return 0;
}
*/