// Application constants
// ------------------------------
new const Colors[.white, .black, .red, .green, .blue, .yellow] = 
[
    0xFFFFFFFF,
    0xFF000000,
    0xFFFF0000,
    0xFF00FF00,
    0xFF0000FF,
    0xFFFFFF00,
];

// Application variables
new Application[.screen,.direction,.animationOffset];

// Word indices help in referencing words from the WordCollection.inc bank
new word1Index = 1153 // Index for HATE
new word2Index = 2596 // Index for STOP
new word3Index = 620  // Index for DICE
new word4Index = 1073 // Index for GOOD
new word5Index = 1620 // Index for LOVE
new word6Index = 845  // Index for FART

new random_seed = -2147483648;
new random_seed_update = -2147483648;

// White face letter collection
new white[] = [0, 0, 0, 0, 0, 0, 0, 0,];

new green[] = [0, 0, 0, 0, 0, 0, 0, 0,];

new yellow[] = [0, 0, 0, 0, 0, 0, 0, 0,];

new blue[] = [0, 0, 0, 0, 0, 0, 0, 0,];

new red[] = [0, 0, 0, 0, 0, 0, 0, 0,];

new orange[] = [0, 0, 0, 0, 0, 0, 0, 0,];

new drawn_facelet_collection[] = 
[
    // White facelets
    -1, -1, -1, 1, // white 1: screen, module, letter, isBlack
    -1, -1, -1, 1, // white 2: screen, module, letter, isBlack
    -1, -1, -1, 1, // white 3: screen, module, letter, isBlack
    -1, -1, -1, 1, // white 4: screen, module, letter, isBlack
    // Green facelets
    -1, -1, -1, 1, // green 1: screen, module, letter, isBlack
    -1, -1, -1, 1, // green 2: screen, module, letter, isBlack
    -1, -1, -1, 1, // green 3: screen, module, letter, isBlack
    -1, -1, -1, 1, // green 4: screen, module, letter, isBlack
    // Yellow facelets
    -1, -1, -1, 1, 
    -1, -1, -1, 1, 
    -1, -1, -1, 1, 
    -1, -1, -1, 1, 
    // Blue facelets
    -1, -1, -1, 1, 
    -1, -1, -1, 1, 
    -1, -1, -1, 1,  
    -1, -1, -1, 1, 
    // Red facelets
    -1, -1, -1, 1, 
    -1, -1, -1, 1, 
    -1, -1, -1, 1, 
    -1, -1, -1, 1, 
    // Orange facelets
    -1, -1, -1, 1, 
    -1, -1, -1, 1, 
    -1, -1, -1, 1, 
    -1, -1, -1, 1, 
]



new direction_facelet_collection[] = 
[
    // Up facelets
    -1, -1, -1, -1, -1, // Up 1: screen, module, letter, rotation, isFirst
    -1, -1, -1, -1, -1, // Up 2: screen, module, letter, rotation, isFirst
    -1, -1, -1, -1, -1, // Up 3: screen, module, letter, rotation, isFirst
    -1, -1, -1, -1, -1, // Up 4: screen, module, letter, rotation, isFirst
    // Front facelets
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1,
    // Down facelets
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    // Back facelets
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    // Left facelets
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    // Right facelets
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
]

new mode_three_collection[] = 
[
    // Up facelets
    -1, -1, -1, -1, -1, // Up 1: screen, module, letter, rotation, isFirst
    -1, -1, -1, -1, -1, // Up 2: screen, module, letter, rotation, isFirst
    -1, -1, -1, -1, -1, // Up 3: screen, module, letter, rotation, isFirst
    -1, -1, -1, -1, -1, // Up 4: screen, module, letter, rotation, isFirst
    // Front facelets
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
    // Down facelets
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
    // Back facelets
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
    // Left facelets
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
    // Right facelets
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
]

//*********** */

new offsets[TOPOLOGY_FACES_MAX] = [180, 270, 90, 270, 0, 0];

new isBlack = true;

new up_track[TOPOLOGY_FACELET]
new front_track[TOPOLOGY_FACELET]
new down_track[TOPOLOGY_FACELET]
new back_track[TOPOLOGY_FACELET]
new left_track[TOPOLOGY_FACELET]
new right_track[TOPOLOGY_FACELET]

new facelet[TOPOLOGY_FACELET_INFO];

new solved[] = [false, false, false, false, false, false];

new game_mode = 0;

new letter_collection[] = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'];