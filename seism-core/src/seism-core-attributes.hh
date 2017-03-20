// seism-core-attributes.hh
#include "hdf5.h"

class seismCoreAttributes 
{

    public:

        char *name;
        hsize_t processor_dims[3];
        hsize_t chunk_dims[3];
        hsize_t domain_dims[3];
        unsigned int simulation_time;
        int collective_write;
        int precreate;
        int set_collective_metadata;
        int never_fill;

        // constructor to create a new attributes object from simulation
        seismCoreAttributes
        (
            char * _name,
            hsize_t *_processor_dims,
            hsize_t *_chunk_dims,
            hsize_t *_domain_dims,
            unsigned int _simulation_time,
            int _collective_write,
            int _precreate,
            int _set_collective_metadata,
            int _never_fill
        );

        // constructor to read attributes object from a file
        seismCoreAttributes(hid_t file_id);

        // called at end of simulation to write attributes out
        void writeAttributesToFile(hid_t file_id);

        // destructor will free H5 resources
        ~seismCoreAttributes();

        hid_t vls_type_c_id; // compound type
        hid_t dim_h5t; // dimension type
        hid_t attributes_h5t; // attributes type

    private:

        void init(); // create H5 objects used internally

};
