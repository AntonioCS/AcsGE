#ifndef COLORLIST_H
#define COLORLIST_H


namespace AcsGameEngine::Util {

//From http://cloford.com/resources/colours/500col.htm;

struct ColorList {
    
    struct Color {
        const int r;
        const int g;
        const int b;

        const char* hex;

        //alpha
        const unsigned int maxAlphaValue{ 255 };
        unsigned int a{ maxAlphaValue };

        bool operator!=(const Color &rhs) const {
            return !(operator==(rhs));
        }
        bool operator==(const Color &rhs) const { 
            return rhs.r == r && rhs.g == g && rhs.b == b && rhs.a == a;
        }

        void alphaPercentage(unsigned int value) noexcept {
            a = value * maxAlphaValue / 100;
        }
    };

    static const Color _nocolor;

    static const Color indian_red;
    static const Color crimson;
    static const Color lightpink;
    static const Color lightpink_1;
    static const Color lightpink_2;
    static const Color lightpink_3;
    static const Color lightpink_4;
    static const Color pink;
    static const Color pink_1;
    static const Color pink_2;
    static const Color pink_3;
    static const Color pink_4;
    static const Color palevioletred;
    static const Color palevioletred_1;
    static const Color palevioletred_2;
    static const Color palevioletred_3;
    static const Color palevioletred_4;

    static const Color lavender_blush;
    static const Color lavenderblush_2;
    static const Color lavenderblush_3;
    static const Color lavenderblush_4;
    static const Color violetred_1;
    static const Color violetred_2;
    static const Color violetred_3;
    static const Color violetred_4;
    static const Color hotpink;
    static const Color hotpink_1;
    static const Color hotpink_2;
    static const Color hotpink_3;
    static const Color hotpink_4;
    static const Color raspberry;

    static const Color deep_pink;
    static const Color deeppink_2;
    static const Color deeppink_3;
    static const Color deeppink_4;
    static const Color maroon_1;
    static const Color maroon_2;
    static const Color maroon_3;
    static const Color maroon_4;
    static const Color mediumvioletred;
    static const Color violetred;
    static const Color orchid;
    static const Color orchid_1;
    static const Color orchid_2;
    static const Color orchid_3;
    static const Color orchid_4;
    static const Color thistle;
    static const Color thistle_1;
    static const Color thistle_2;
    static const Color thistle_3;
    static const Color thistle_4;
    static const Color plum_1;
    static const Color plum_2;
    static const Color plum_3;
    static const Color plum_4;
    static const Color plum;
    static const Color violet;

    static const Color fuchsia;
    static const Color magenta_2;
    static const Color magenta_3;

    static const Color dark_magenta;
    static const Color purple;
    static const Color mediumorchid;
    static const Color mediumorchid_1;
    static const Color mediumorchid_2;
    static const Color mediumorchid_3;
    static const Color mediumorchid_4;
    static const Color darkviolet;
    static const Color darkorchid;
    static const Color darkorchid_1;
    static const Color darkorchid_2;
    static const Color darkorchid_3;
    static const Color darkorchid_4;
    static const Color indigo;
    static const Color blueviolet;
    static const Color purple_1;
    static const Color purple_2;
    static const Color purple_3;
    static const Color purple_4;
    static const Color mediumpurple;
    static const Color mediumpurple_1;
    static const Color mediumpurple_2;
    static const Color mediumpurple_3;
    static const Color mediumpurple_4;
    static const Color darkslateblue;
    static const Color lightslateblue;
    static const Color mediumslateblue;
    static const Color slateblue;
    static const Color slateblue_1;
    static const Color slateblue_2;
    static const Color slateblue_3;
    static const Color slateblue_4;
    static const Color ghostwhite;
    static const Color lavender;
    static const Color blue;
    static const Color blue_2;

    static const Color mediumblue;

    static const Color dark_blue;
    static const Color navy;
    static const Color midnight_blue;
    static const Color cobalt;
    static const Color royal_blue;
    static const Color royal_blue_1;
    static const Color royal_blue_2;
    static const Color royal_blue_3;
    static const Color royal_blue_4;
    static const Color cornflowerblue;
    static const Color lightsteelblue;
    static const Color lightsteelblue_1;
    static const Color lightsteelblue_2;
    static const Color lightsteelblue_3;
    static const Color lightsteelblue_4;
    static const Color lightslategray;
    static const Color slategray;
    static const Color slategray_1;
    static const Color slategray_2;
    static const Color slategray_3;
    static const Color slategray_4;

    static const Color dodger_blue;
    static const Color dodgerblue_2;
    static const Color dodgerblue_3;
    static const Color dodgerblue_4;
    static const Color aliceblue;
    static const Color steelblue;
    static const Color steelblue_1;
    static const Color steelblue_2;
    static const Color steelblue_3;
    static const Color steelblue_4;
    static const Color lightskyblue;
    static const Color lightskyblue_1;
    static const Color lightskyblue_2;
    static const Color lightskyblue_3;
    static const Color lightskyblue_4;
    static const Color skyblue_1;
    static const Color skyblue_2;
    static const Color skyblue_3;
    static const Color skyblue_4;
    static const Color skyblue;

    static const Color deep_sky_blue;
    static const Color deep_sky_blue_2;
    static const Color deep_sky_blue_3;
    static const Color deep_sky_blue_4;
    static const Color peacock;
    static const Color lightblue;
    static const Color lightblue_1;
    static const Color lightblue_2;
    static const Color lightblue_3;
    static const Color lightblue_4;
    static const Color powderblue;
    static const Color cadetblue_1;
    static const Color cadetblue_2;
    static const Color cadetblue_3;
    static const Color cadetblue_4;
    static const Color turquoise_1;
    static const Color turquoise_2;
    static const Color turquoise_3;
    static const Color turquoise_4;
    static const Color cadetblue;
    static const Color darkturquoise;

    static const Color azure;
    static const Color azure_2;
    static const Color azure_3;
    static const Color azure_4;

    static const Color light_cyan;
    static const Color lightcyan_2;
    static const Color lightcyan_3;
    static const Color lightcyan_4;
    static const Color paleturquoise_1;

    static const Color pale_turquoise;
    static const Color paleturquoise_3;
    static const Color paleturquoise_4;
    static const Color darkslategray;
    static const Color darkslategray_1;
    static const Color darkslategray_2;
    static const Color darkslategray_3;
    static const Color darkslategray_4;
    static const Color cyan_aqua;
    static const Color cyan_2;
    static const Color cyan_3;

    static const Color dark_cyan;
    static const Color teal;
    static const Color mediumturquoise;
    static const Color lightseagreen;
    static const Color manganeseblue;
    static const Color turquoise;
    static const Color coldgrey;
    static const Color turquoiseblue;

    static const Color aquamarine;
    static const Color aquamarine_2;

    static const Color medium_aquamarine;
    static const Color aquamarine_4;
    static const Color mediumspringgreen;
    static const Color mintcream;
    static const Color springgreen;
    static const Color springgreen_1;
    static const Color springgreen_2;
    static const Color springgreen_3;
    static const Color mediumseagreen;
    static const Color seagreen_1;
    static const Color seagreen_2;
    static const Color seagreen_3;

    static const Color seagreen;
    static const Color emeraldgreen;
    static const Color mint;
    static const Color cobaltgreen;

    static const Color honeydew;
    static const Color honeydew_2;
    static const Color honeydew_3;
    static const Color honeydew_4;
    static const Color darkseagreen;
    static const Color darkseagreen_1;
    static const Color darkseagreen_2;
    static const Color darkseagreen_3;
    static const Color darkseagreen_4;
    static const Color palegreen;
    static const Color palegreen_1;

    static const Color lightgreen;
    static const Color palegreen_3;
    static const Color palegreen_4;
    static const Color limegreen;
    static const Color forestgreen;

    static const Color lime;
    static const Color green_2;
    static const Color green_3;
    static const Color green_4;
    static const Color green;
    static const Color darkgreen;
    static const Color sapgreen;
    static const Color lawngreen;

    static const Color chartreuse;
    static const Color chartreuse_2;
    static const Color chartreuse_3;
    static const Color chartreuse_4;
    static const Color greenyellow;
    static const Color darkolivegreen_1;
    static const Color darkolivegreen_2;
    static const Color darkolivegreen_3;
    static const Color darkolivegreen_4;
    static const Color darkolivegreen;
    static const Color olivedrab;
    static const Color olivedrab_1;
    static const Color olivedrab_2;

    static const Color yellowgreen;
    static const Color olivedrab_4;

    static const Color ivory;
    static const Color ivory_2;
    static const Color ivory_3;
    static const Color ivory_4;
    static const Color beige;

    static const Color lightyellow;
    static const Color lightyellow_2;
    static const Color lightyellow_3;
    static const Color lightyellow_4;
    static const Color lightgoldenrodyellow;

    static const Color yellow;
    static const Color yellow_2;
    static const Color yellow_3;
    static const Color yellow_4;
    static const Color warmgrey;
    static const Color olive;
    static const Color darkkhaki;
    static const Color khaki_1;
    static const Color khaki_2;
    static const Color khaki_3;
    static const Color khaki_4;
    static const Color khaki;
    static const Color palegoldenrod;

    static const Color lemonchiffon;
    static const Color lemonchiffon_2;
    static const Color lemonchiffon_3;
    static const Color lemonchiffon_4;
    static const Color lightgoldenrod_1;
    static const Color lightgoldenrod_2;
    static const Color lightgoldenrod_3;
    static const Color lightgoldenrod_4;
    static const Color banana;

    static const Color gold;
    static const Color gold_2;
    static const Color gold_3;
    static const Color gold_4;

    static const Color cornsilk;
    static const Color cornsilk_2;
    static const Color cornsilk_3;
    static const Color cornsilk_4;
    static const Color goldenrod;
    static const Color goldenrod_1;
    static const Color goldenrod_2;
    static const Color goldenrod_3;
    static const Color goldenrod_4;
    static const Color darkgoldenrod;
    static const Color darkgoldenrod_1;
    static const Color darkgoldenrod_2;
    static const Color darkgoldenrod_3;
    static const Color darkgoldenrod_4;

    static const Color orange_1;
    static const Color orange_2;
    static const Color orange_3;
    static const Color orange_4;
    static const Color floralwhite;
    static const Color oldlace;
    static const Color wheat;
    static const Color wheat_1;
    static const Color wheat_2;
    static const Color wheat_3;
    static const Color wheat_4;
    static const Color moccasin;
    static const Color papayawhip;
    static const Color blanchedalmond;

    static const Color navajowhite;
    static const Color navajowhite_2;
    static const Color navajowhite_3;
    static const Color navajowhite_4;
    static const Color eggshell;
    static const Color tan;
    static const Color brick;
    static const Color cadmiumyellow;
    static const Color antiquewhite;
    static const Color antiquewhite_1;
    static const Color antiquewhite_2;
    static const Color antiquewhite_3;
    static const Color antiquewhite_4;
    static const Color burlywood;
    static const Color burlywood_1;
    static const Color burlywood_2;
    static const Color burlywood_3;
    static const Color burlywood_4;
    static const Color bisque;
    static const Color bisque_2;
    static const Color bisque_3;
    static const Color bisque_4;
    static const Color melon;
    static const Color carrot;
    static const Color darkorange;
    static const Color darkorange_1;
    static const Color darkorange_2;
    static const Color darkorange_3;
    static const Color darkorange_4;
    static const Color orange;
    static const Color tan_1;
    static const Color tan_2;

    static const Color peru;
    static const Color tan_4;
    static const Color linen;

    static const Color peachpuff;
    static const Color peachpuff_2;
    static const Color peachpuff_3;
    static const Color peachpuff_4;

    static const Color seashell;
    static const Color seashell_2;
    static const Color seashell_3;
    static const Color seashell_4;
    static const Color sandybrown;
    static const Color rawsienna;
    static const Color chocolate;
    static const Color chocolate_1;
    static const Color chocolate_2;
    static const Color chocolate_3;

    static const Color saddlebrown;
    static const Color ivoryblack;
    static const Color flesh;
    static const Color cadmiumorange;
    static const Color burntsienna;
    static const Color sienna;
    static const Color sienna_1;
    static const Color sienna_2;
    static const Color sienna_3;
    static const Color sienna_4;

    static const Color lightsalmon;
    static const Color lightsalmon_2;
    static const Color lightsalmon_3;
    static const Color lightsalmon_4;
    static const Color coral;

    static const Color orangered;
    static const Color orangered_2;
    static const Color orangered_3;
    static const Color orangered_4;
    static const Color sepia;
    static const Color darksalmon;
    static const Color salmon_1;
    static const Color salmon_2;
    static const Color salmon_3;
    static const Color salmon_4;
    static const Color coral_1;
    static const Color coral_2;
    static const Color coral_3;
    static const Color coral_4;
    static const Color burntumber;
    static const Color tomato;
    static const Color tomato_2;
    static const Color tomato_3;
    static const Color tomato_4;
    static const Color salmon;
    static const Color mistyrose;
    static const Color mistyrose_2;
    static const Color mistyrose_3;
    static const Color mistyrose_4;
    static const Color snow;
    static const Color snow_2;
    static const Color snow_3;
    static const Color snow_4;
    static const Color rosybrown;
    static const Color rosybrown_1;
    static const Color rosybrown_2;
    static const Color rosybrown_3;
    static const Color rosybrown_4;
    static const Color lightcoral;
    static const Color indianred;
    static const Color indianred_1;
    static const Color indianred_2;
    static const Color indianred_4;
    static const Color indianred_3;
    static const Color brown;
    static const Color brown_1;
    static const Color brown_2;
    static const Color brown_3;
    static const Color brown_4;
    static const Color firebrick;
    static const Color firebrick_1;
    static const Color firebrick_2;
    static const Color firebrick_3;
    static const Color firebrick_4;

    static const Color red;
    static const Color red_2;
    static const Color red_3;

    static const Color dark_red;
    static const Color maroon;
    static const Color sgi_beet;
    static const Color sgi_slateblue;
    static const Color sgi_lightblue;
    static const Color sgi_teal;
    static const Color sgi_chartreuse;
    static const Color sgi_olivedrab;
    static const Color sgi_brightgray;
    static const Color sgi_salmon;
    static const Color sgi_darkgray;
    static const Color sgi_gray_12;
    static const Color sgi_gray_16;
    static const Color sgi_gray_32;
    static const Color sgi_gray_36;
    static const Color sgi_gray_52;
    static const Color sgi_gray_56;
    static const Color sgi_lightgray;
    static const Color sgi_gray_72;
    static const Color sgi_gray_76;
    static const Color sgi_gray_92;
    static const Color sgi_gray_96;
    static const Color white;
    static const Color white_smoke;
    static const Color gainsboro;
    static const Color lightgrey;
    static const Color silver;
    static const Color darkgray;
    static const Color gray;

    static const Color dimgray;
    static const Color black;
    static const Color gray_99;
    static const Color gray_98;
    static const Color gray_97;

    static const Color gray_95;
    static const Color gray_94;
    static const Color gray_93;
    static const Color gray_92;
    static const Color gray_91;
    static const Color gray_90;
    static const Color gray_89;
    static const Color gray_88;
    static const Color gray_87;
    static const Color gray_86;
    static const Color gray_85;
    static const Color gray_84;
    static const Color gray_83;
    static const Color gray_82;
    static const Color gray_81;
    static const Color gray_80;
    static const Color gray_79;
    static const Color gray_78;
    static const Color gray_77;
    static const Color gray_76;
    static const Color gray_75;
    static const Color gray_74;
    static const Color gray_73;
    static const Color gray_72;
    static const Color gray_71;
    static const Color gray_70;
    static const Color gray_69;
    static const Color gray_68;
    static const Color gray_67;
    static const Color gray_66;
    static const Color gray_65;
    static const Color gray_64;
    static const Color gray_63;
    static const Color gray_62;
    static const Color gray_61;
    static const Color gray_60;
    static const Color gray_59;
    static const Color gray_58;
    static const Color gray_57;
    static const Color gray_56;
    static const Color gray_55;
    static const Color gray_54;
    static const Color gray_53;
    static const Color gray_52;
    static const Color gray_51;
    static const Color gray_50;
    static const Color gray_49;
    static const Color gray_48;
    static const Color gray_47;
    static const Color gray_46;
    static const Color gray_45;
    static const Color gray_44;
    static const Color gray_43;
    static const Color gray_42;
    static const Color dimgray_gray;
    static const Color gray_40;
    static const Color gray_39;
    static const Color gray_38;
    static const Color gray_37;
    static const Color gray_36;
    static const Color gray_35;
    static const Color gray_34;
    static const Color gray_33;
    static const Color gray_32;
    static const Color gray_31;
    static const Color gray_30;
    static const Color gray_29;
    static const Color gray_28;
    static const Color gray_27;
    static const Color gray_26;
    static const Color gray_25;
    static const Color gray_24;
    static const Color gray_23;
    static const Color gray_22;
    static const Color gray_21;
    static const Color gray_20;
    static const Color gray_19;
    static const Color gray_18;
    static const Color gray_17;
    static const Color gray_16;
    static const Color gray_15;
    static const Color gray_14;
    static const Color gray_13;
    static const Color gray_12;
    static const Color gray_11;
    static const Color gray_10;
    static const Color gray_9;
    static const Color gray_8;
    static const Color gray_7;
    static const Color gray_6;
    static const Color gray_5;
    static const Color gray_4;
    static const Color gray_3;
    static const Color gray_2;
    static const Color gray_1;
};
} // namespace AcsGameEngine::Util
#endif // COLORLIST_H
