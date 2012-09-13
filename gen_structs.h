
cpBody body {
        Mass( float m ),
        MassInverse( float m_inv ),
        Moment( float i ),
        MomentInverse( float i_inv ),

        Pos( cpVect p ),
        Vel( cpVect v ),
        Force( cpVect f ),
        VelBias( cpVect v_bias ),

        Angle( float a ),
        AVel( float w ),
        Torque( float t ),
        AVelBias( float w_bias ),

        Rot( cpVect rot ),

        VelLim( float v_limit ),
        AngVelLim( float w_limit ),
};


cpSpace space {
        Iterations( int iterations ),

        Gravity( cpVect gravity ),
        Damping( float damping ),

        ElasticIterations( int elasticIterations ),

        Stamp( int_readonly stamp ),

//      Bodies( cpArray bodies ),
};


// Seems that the author would be willing to make
// this structure disappear in futur versions.
//
//cpArray cp_array {
//      Num( int num ),
//      Max( int max ),
//      void **arr;
//};


cpShape shape {
        Elasticity( float e ),
        Friction( float u ),
        SurfaceV( cpVect surface_v ),

// User defined collision type for the shape.
        CollisionType( int collision_type ),
// User defined collision group for the shape.
        Group( int group ),
// User defined layer bitmask for the shape.
        Layers( int layers ),

// Unique id used as the hash value.
        HashID( cpHashValue hashid ),
};


cpCircleShape circle_shape {
        Center( cpVect c ),
        Radius( float r ),
};


cpSegmentShape segment_shape {
//      Shape( cpShape shape ),

        A( cpVect a ),
        B( cpVect b ),
        Norm( cpVect n ),

        Thickness( float r ),

        TA( cpVect ta ),
        TB( cpVect tb ),
        TNorm( cpVect tn ),
};


cpPolyShape poly {
//      Shape( cpShape shape ),
        
        NumVerts( int_readonly numVerts ),
        Vects( cpVectArray verts ),
//      cpPolyShapeAxis *axes;

        TVerts( cpVectArray tVerts ),
//      cpPolyShapeAxis *tAxes;
};


cpPinJoint pin_joint {
//      cpConstraint constraint;
        Anchor1( cpVect anchr1 ),
        Anchor2( cpVect anchr2 ),
        Dist( cpFloat dist),

        R1( cpVect r1 ),
        R2( cpVect r2 ),
        Vect( cpVect n ),
        NMass( cpFloat nMass ),

        JNAcc( cpFloat jnAcc ),
        JNMax( cpFloat jnMax ),
        Bias( cpFloat bias ),
};


cpSlideJoint slide_joint {
//      cpJoint joint;
        Anchor1( cpVect anchr1 ),
        Anchor2( cpVect anchr2 ),
        Min( cpFloat min ),
        Max( cpFloat max ),
        
        R1( cpVect r1 ),
        R2( cpVect r2 ),
        Vect( cpVect n ),
        NMass( cpFloat nMass ),
        
        JNAcc( cpFloat jnAcc ),
        JNMax( cpFloat jnMax ),
        Bias( cpFloat bias ),
};


cpPivotJoint pivot_joint {
//      cpJoint joint;
        Anchor1( cpVect anchr1 ),
        Anchor2( cpVect anchr2 ),

        R1( cpVect r1 ),
        R2( cpVect r2 ),

        K1( cpVect k1 ),
        K2( cpVect k2 ),

        JAcc( cpVect jAcc ),
        JMaxLen( cpFloat jMaxLen ),
        Bias( cpVect bias ),
};


cpGrooveJoint groove_joint {
//      cpJoint joint;
        GrvN( cpVect grv_n ),
        GrvA( cpVect grv_a ),
        GrvB( cpVect grv_b ),
        Anchor2( cpVect anchr2 ),

        GrvTn( cpVect grv_tn ),
        Clamp( cpFloat clamp ),

        R1( cpVect r1 ),
        R2( cpVect r2 ),

        K1( cpVect k1 ),
        K2( cpVect k2 ),

        JAcc( cpVect jAcc ),
        JMaxLen( cpFloat jMaxLen ),
        Bias( cpVect bias ),
};


// Data structure for contact points.
cpContact cp_contact {
// Contact point and normal.
        P( cpVect p ),
        N( cpVect n ),
// Penetration distance.
        Dist( cpFloat dist ),

// Calculated by cpArbiterPreStep().
        R1( cpVect r1 ),
        R2( cpVect r2 ),
        NMass( cpFloat nMass ),
        TMass( cpFloat tMass ),
        Bounce( cpFloat bounce ),

// Persistant contact information.
        JNAcc( cpFloat jnAcc ),
        JTAcc( cpFloat jtAcc ),
        JBias( cpFloat jBias ),
        Bias( cpFloat bias ),

// Hash value used to (mostly) uniquely identify a contact.
//      unsigned int hash;
        Hash( int hash ),
};


// Data structure for tracking collisions between shapes.
cpArbiter arbiter {
// Information on the contact points between the objects.
        NumContacts( int numContacts ),
//      cpContact *contacts;

// The two shapes involved in the collision.
// These variables are NOT in the order defined by the collision handler.
        PA( cpShape a ),
        PB( cpShape b ),

// Calculated before calling the pre-solve collision handler
// Override them with custom values if you want specialized behavior
        E( cpFloat e ),
        U( cpFloat u ),
// Used for surface_v calculations, implementation may change
        Surface_vr( cpVect surface_vr),

// Time stamp of the arbiter. (from cpSpace)
        Stamp( int stamp ),

//      struct cpCollisionHandler *handler;

// Are the shapes swapped in relation to the collision handler?
        SwappedColl( char swappedColl ),
        State( char state ),
};



cpBB bb {
        L( cpFloat l ),
        B( cpFloat b ),
        R( cpFloat r ),
        T( cpFloat t ),
} cpBB;


// vim: et
