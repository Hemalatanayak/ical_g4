# Codes for Simulations of INO-ICAL detector (simplified geometry) 
##  ICAL geometry /MICAL geometry
This code uses the geometry description stored in GDML files. An example file can be found in https://github.com/Hemalatanayak/ical_geometry.git
* The code here automatically sets the magnetic field in the Iron layers to 1.5 T along Y axis (uniform). See **G01DetectorConstruction.hh** for implementation details.
## Usage Instructions
- Required: geant4-v11.0.3 
- clone this repository into a folder of your choice (call it repo)
- create a build folder and call `cmake repo`
- type `make`
- There are two ways of running the code:
    -  `./mical_g4 ical_geometry.gdml  ` 
    - This command will show the visualization of the geometry and tracks 
    -  `./mical_g4 ical_geometry.gdml run.mac ` 
    - This command will not show the visualization but run the commands in the run.mac file
- The output is stored in a file named `ical_output_nt_ical_data.csv` (or similar) which contains the undigitized positions of the particles crossing the glass plates, time and momentum.
- The code in track.py can be used to visualize the events stored in the output file.


