/*
 * NVIC.h
 *
 *  Created on: Apr 10, 2022
 *      Author: Mohamed Hosny
 */

#ifndef NVIC_H_
#define NVIC_H_

#define NVIC_u8ACTIVESTATUS_LOW 		 0
#define NVIC_u8ACTIVESTATUS_HIGH 		 1

#define NVIC_u8IRQ_NUM_0                 0
#define NVIC_u8IRQ_NUM_1                 1
#define NVIC_u8IRQ_NUM_2                 2
#define NVIC_u8IRQ_NUM_3                 3
#define NVIC_u8IRQ_NUM_4                 4
#define NVIC_u8IRQ_NUM_5                 5
#define NVIC_u8IRQ_NUM_6                 6
#define NVIC_u8IRQ_NUM_7                 7
#define NVIC_u8IRQ_NUM_8                 8
#define NVIC_u8IRQ_NUM_9                 9
#define NVIC_u8IRQ_NUM_10                10
#define NVIC_u8IRQ_NUM_11                11
#define NVIC_u8IRQ_NUM_12                12
#define NVIC_u8IRQ_NUM_13                13
#define NVIC_u8IRQ_NUM_14                14
#define NVIC_u8IRQ_NUM_15                15
#define NVIC_u8IRQ_NUM_16                16
#define NVIC_u8IRQ_NUM_17                17
#define NVIC_u8IRQ_NUM_18                18
#define NVIC_u8IRQ_NUM_19                19
#define NVIC_u8IRQ_NUM_20                20
#define NVIC_u8IRQ_NUM_21                21
#define NVIC_u8IRQ_NUM_22                22
#define NVIC_u8IRQ_NUM_23                23
#define NVIC_u8IRQ_NUM_24                24
#define NVIC_u8IRQ_NUM_25                25
#define NVIC_u8IRQ_NUM_26                26
#define NVIC_u8IRQ_NUM_27                27
#define NVIC_u8IRQ_NUM_28                28
#define NVIC_u8IRQ_NUM_29                29
#define NVIC_u8IRQ_NUM_30                30
#define NVIC_u8IRQ_NUM_31                31
#define NVIC_u8IRQ_NUM_32                32
#define NVIC_u8IRQ_NUM_33                33
#define NVIC_u8IRQ_NUM_34                34
#define NVIC_u8IRQ_NUM_35                35
#define NVIC_u8IRQ_NUM_36                36
#define NVIC_u8IRQ_NUM_37                37
#define NVIC_u8IRQ_NUM_38                38
#define NVIC_u8IRQ_NUM_39                39
#define NVIC_u8IRQ_NUM_40                40
#define NVIC_u8IRQ_NUM_41                41
#define NVIC_u8IRQ_NUM_42                42
#define NVIC_u8IRQ_NUM_43                43
#define NVIC_u8IRQ_NUM_44                44
#define NVIC_u8IRQ_NUM_45                45
#define NVIC_u8IRQ_NUM_46                46
#define NVIC_u8IRQ_NUM_47                47
#define NVIC_u8IRQ_NUM_48                48
#define NVIC_u8IRQ_NUM_49                49
#define NVIC_u8IRQ_NUM_50                50
#define NVIC_u8IRQ_NUM_51                51
#define NVIC_u8IRQ_NUM_52                52
#define NVIC_u8IRQ_NUM_53                53
#define NVIC_u8IRQ_NUM_54                54
#define NVIC_u8IRQ_NUM_55                55
#define NVIC_u8IRQ_NUM_56                56
#define NVIC_u8IRQ_NUM_57                57
#define NVIC_u8IRQ_NUM_58                58
#define NVIC_u8IRQ_NUM_59                59
#define NVIC_u8IRQ_NUM_60                60
#define NVIC_u8IRQ_NUM_61                61
#define NVIC_u8IRQ_NUM_62                62
#define NVIC_u8IRQ_NUM_63                63
#define NVIC_u8IRQ_NUM_64                64
#define NVIC_u8IRQ_NUM_65                65
#define NVIC_u8IRQ_NUM_66                66
#define NVIC_u8IRQ_NUM_67                67
#define NVIC_u8IRQ_NUM_68                68
#define NVIC_u8IRQ_NUM_69                69
#define NVIC_u8IRQ_NUM_70                70
#define NVIC_u8IRQ_NUM_71                71
#define NVIC_u8IRQ_NUM_72                72
#define NVIC_u8IRQ_NUM_73                73
#define NVIC_u8IRQ_NUM_74                74
#define NVIC_u8IRQ_NUM_75                75
#define NVIC_u8IRQ_NUM_76                76
#define NVIC_u8IRQ_NUM_77                77
#define NVIC_u8IRQ_NUM_78                78
#define NVIC_u8IRQ_NUM_79                79
#define NVIC_u8IRQ_NUM_80                80
#define NVIC_u8IRQ_NUM_81                81
#define NVIC_u8IRQ_NUM_82                82
#define NVIC_u8IRQ_NUM_83                83
#define NVIC_u8IRQ_NUM_84                84
#define NVIC_u8IRQ_NUM_85                85
#define NVIC_u8IRQ_NUM_86                86
#define NVIC_u8IRQ_NUM_87                87
#define NVIC_u8IRQ_NUM_88                88
#define NVIC_u8IRQ_NUM_89                89
#define NVIC_u8IRQ_NUM_90                90
#define NVIC_u8IRQ_NUM_91                91
#define NVIC_u8IRQ_NUM_92                92
#define NVIC_u8IRQ_NUM_93                93
#define NVIC_u8IRQ_NUM_94                94
#define NVIC_u8IRQ_NUM_95                95
#define NVIC_u8IRQ_NUM_96                96
#define NVIC_u8IRQ_NUM_97                97
#define NVIC_u8IRQ_NUM_98                98
#define NVIC_u8IRQ_NUM_99                99
#define NVIC_u8IRQ_NUM_100               100
#define NVIC_u8IRQ_NUM_101               101
#define NVIC_u8IRQ_NUM_102               102
#define NVIC_u8IRQ_NUM_103               103
#define NVIC_u8IRQ_NUM_104               104
#define NVIC_u8IRQ_NUM_105               105
#define NVIC_u8IRQ_NUM_106               106
#define NVIC_u8IRQ_NUM_107               107
#define NVIC_u8IRQ_NUM_108               108
#define NVIC_u8IRQ_NUM_109               109
#define NVIC_u8IRQ_NUM_110               110
#define NVIC_u8IRQ_NUM_111               111
#define NVIC_u8IRQ_NUM_112               112
#define NVIC_u8IRQ_NUM_113               113
#define NVIC_u8IRQ_NUM_114               114
#define NVIC_u8IRQ_NUM_115               115
#define NVIC_u8IRQ_NUM_116               116
#define NVIC_u8IRQ_NUM_117               117
#define NVIC_u8IRQ_NUM_118               118
#define NVIC_u8IRQ_NUM_119               119
#define NVIC_u8IRQ_NUM_120               120
#define NVIC_u8IRQ_NUM_121               121
#define NVIC_u8IRQ_NUM_122               122
#define NVIC_u8IRQ_NUM_123               123
#define NVIC_u8IRQ_NUM_124               124
#define NVIC_u8IRQ_NUM_125               125
#define NVIC_u8IRQ_NUM_126               126
#define NVIC_u8IRQ_NUM_127               127
#define NVIC_u8IRQ_NUM_128               128
#define NVIC_u8IRQ_NUM_129               129
#define NVIC_u8IRQ_NUM_130               130
#define NVIC_u8IRQ_NUM_131               131
#define NVIC_u8IRQ_NUM_132               132
#define NVIC_u8IRQ_NUM_133               133
#define NVIC_u8IRQ_NUM_134               134
#define NVIC_u8IRQ_NUM_135               135
#define NVIC_u8IRQ_NUM_136               136
#define NVIC_u8IRQ_NUM_137               137
#define NVIC_u8IRQ_NUM_138               138
#define NVIC_u8IRQ_NUM_139               139
#define NVIC_u8IRQ_NUM_140               140
#define NVIC_u8IRQ_NUM_141               141
#define NVIC_u8IRQ_NUM_142               142
#define NVIC_u8IRQ_NUM_143               143
#define NVIC_u8IRQ_NUM_144               144
#define NVIC_u8IRQ_NUM_145               145
#define NVIC_u8IRQ_NUM_146               146
#define NVIC_u8IRQ_NUM_147               147
#define NVIC_u8IRQ_NUM_148               148
#define NVIC_u8IRQ_NUM_149               149
#define NVIC_u8IRQ_NUM_150               150
#define NVIC_u8IRQ_NUM_151               151
#define NVIC_u8IRQ_NUM_152               152
#define NVIC_u8IRQ_NUM_153               153
#define NVIC_u8IRQ_NUM_154               154
#define NVIC_u8IRQ_NUM_155               155
#define NVIC_u8IRQ_NUM_156               156
#define NVIC_u8IRQ_NUM_157               157
#define NVIC_u8IRQ_NUM_158               158
#define NVIC_u8IRQ_NUM_159               159
#define NVIC_u8IRQ_NUM_160               160
#define NVIC_u8IRQ_NUM_161               161
#define NVIC_u8IRQ_NUM_162               162
#define NVIC_u8IRQ_NUM_163               163
#define NVIC_u8IRQ_NUM_164               164
#define NVIC_u8IRQ_NUM_165               165
#define NVIC_u8IRQ_NUM_166               166
#define NVIC_u8IRQ_NUM_167               167
#define NVIC_u8IRQ_NUM_168               168
#define NVIC_u8IRQ_NUM_169               169
#define NVIC_u8IRQ_NUM_170               170
#define NVIC_u8IRQ_NUM_171               171
#define NVIC_u8IRQ_NUM_172               172
#define NVIC_u8IRQ_NUM_173               173
#define NVIC_u8IRQ_NUM_174               174
#define NVIC_u8IRQ_NUM_175               175
#define NVIC_u8IRQ_NUM_176               176
#define NVIC_u8IRQ_NUM_177               177
#define NVIC_u8IRQ_NUM_178               178
#define NVIC_u8IRQ_NUM_179               179
#define NVIC_u8IRQ_NUM_180               180
#define NVIC_u8IRQ_NUM_181               181
#define NVIC_u8IRQ_NUM_182               182
#define NVIC_u8IRQ_NUM_183               183
#define NVIC_u8IRQ_NUM_184               184
#define NVIC_u8IRQ_NUM_185               185
#define NVIC_u8IRQ_NUM_186               186
#define NVIC_u8IRQ_NUM_187               187
#define NVIC_u8IRQ_NUM_188               188
#define NVIC_u8IRQ_NUM_189               189
#define NVIC_u8IRQ_NUM_190               190
#define NVIC_u8IRQ_NUM_191               191
#define NVIC_u8IRQ_NUM_192               192
#define NVIC_u8IRQ_NUM_193               193
#define NVIC_u8IRQ_NUM_194               194
#define NVIC_u8IRQ_NUM_195               195
#define NVIC_u8IRQ_NUM_196               196
#define NVIC_u8IRQ_NUM_197               197
#define NVIC_u8IRQ_NUM_198               198
#define NVIC_u8IRQ_NUM_199               199
#define NVIC_u8IRQ_NUM_200               200
#define NVIC_u8IRQ_NUM_201               201
#define NVIC_u8IRQ_NUM_202               202
#define NVIC_u8IRQ_NUM_203               203
#define NVIC_u8IRQ_NUM_204               204
#define NVIC_u8IRQ_NUM_205               205
#define NVIC_u8IRQ_NUM_206               206
#define NVIC_u8IRQ_NUM_207               207
#define NVIC_u8IRQ_NUM_208               208
#define NVIC_u8IRQ_NUM_209               209
#define NVIC_u8IRQ_NUM_210               210
#define NVIC_u8IRQ_NUM_211               211
#define NVIC_u8IRQ_NUM_212               212
#define NVIC_u8IRQ_NUM_213               213
#define NVIC_u8IRQ_NUM_214               214
#define NVIC_u8IRQ_NUM_215               215
#define NVIC_u8IRQ_NUM_216               216
#define NVIC_u8IRQ_NUM_217               217
#define NVIC_u8IRQ_NUM_218               218
#define NVIC_u8IRQ_NUM_219               219
#define NVIC_u8IRQ_NUM_220               220
#define NVIC_u8IRQ_NUM_221               221
#define NVIC_u8IRQ_NUM_222               222
#define NVIC_u8IRQ_NUM_223               223
#define NVIC_u8IRQ_NUM_224               224
#define NVIC_u8IRQ_NUM_225               225
#define NVIC_u8IRQ_NUM_226               226
#define NVIC_u8IRQ_NUM_227               227
#define NVIC_u8IRQ_NUM_228               228
#define NVIC_u8IRQ_NUM_229               229
#define NVIC_u8IRQ_NUM_230               230
#define NVIC_u8IRQ_NUM_231               231
#define NVIC_u8IRQ_NUM_232               232
#define NVIC_u8IRQ_NUM_233               233
#define NVIC_u8IRQ_NUM_234               234
#define NVIC_u8IRQ_NUM_235               235
#define NVIC_u8IRQ_NUM_236               236
#define NVIC_u8IRQ_NUM_237               237
#define NVIC_u8IRQ_NUM_238               238
#define NVIC_u8IRQ_NUM_239               239

#define NVIC_u8PREEMT_PRIO_LEVEL_0		 0
#define NVIC_u8PREEMT_PRIO_LEVEL_1		 1
#define NVIC_u8PREEMT_PRIO_LEVEL_2		 2
#define NVIC_u8PREEMT_PRIO_LEVEL_3		 3
#define NVIC_u8PREEMT_PRIO_LEVEL_4		 4
#define NVIC_u8PREEMT_PRIO_LEVEL_5		 5
#define NVIC_u8PREEMT_PRIO_LEVEL_6		 6
#define NVIC_u8PREEMT_PRIO_LEVEL_7       7

#define NVIC_u8SUB_GROUP_PRIO_LEVEL_0	0x00
#define NVIC_u8SUB_GROUP_PRIO_LEVEL_1	0x10
#define NVIC_u8SUB_GROUP_PRIO_LEVEL_2   0x20
#define NVIC_u8SUB_GROUP_PRIO_LEVEL_3   0x30
#define NVIC_u8SUB_GROUP_PRIO_LEVEL_4   0x40
#define NVIC_u8SUB_GROUP_PRIO_LEVEL_5   0x50
#define NVIC_u8SUB_GROUP_PRIO_LEVEL_6   0x60
#define NVIC_u8SUB_GROUP_PRIO_LEVEL_7   0x70
#define NVIC_u8SUB_GROUP_PRIO_LEVEL_8   0x80
#define NVIC_u8SUB_GROUP_PRIO_LEVEL_9   0x00
#define NVIC_u8SUB_GROUP_PRIO_LEVEL_10  0xA0
#define NVIC_u8SUB_GROUP_PRIO_LEVEL_11  0xB0
#define NVIC_u8SUB_GROUP_PRIO_LEVEL_12  0xC0
#define NVIC_u8SUB_GROUP_PRIO_LEVEL_13  0xD0
#define NVIC_u8SUB_GROUP_PRIO_LEVEL_14  0xE0
#define NVIC_u8SUB_GROUP_PRIO_LEVEL_15  0xF0

#define NVIC_u32SUB_GROUP_BITS_NUM_1	0x05FA0400
#define NVIC_u32SUB_GROUP_BITS_NUM_2	0x05FA0500
#define NVIC_u32SUB_GROUP_BITS_NUM_3	0x05FA0600
#define NVIC_u32SUB_GROUP_BITS_NUM_4	0x05FA0700

typedef enum{
	NVIC_enuOk,
	NVIC_enuWrongIpParameter,
	NVIC_enuNullPointer
}NVIC_tenuErrorStatus;

NVIC_tenuErrorStatus NVIC_enuEnableIRQ(u8 Copy_u8IRQNum);
NVIC_tenuErrorStatus NVIC_enuDisableIRQ(u8 Copy_u8IRQNum);
NVIC_tenuErrorStatus NVIC_enuSetPendingIRQ(u8 Copy_u8IRQNum);
NVIC_tenuErrorStatus NVIC_enuClearPendingIRQ(u8 Copy_u8IRQNum);
NVIC_tenuErrorStatus NVIC_enuGetActiveIRQ(u8 Copy_u8IRQNum,pu8 Add_pu8ActiveStatusReturn);
NVIC_tenuErrorStatus NVIC_enuSetSubGroupBitsNum(u32 Copy_u32SubGroupBitsNum);
u8 NVIC_enuEncodePriority(u8 Copy_u8PreemtLevel,u8 Copy_u8SubGroupLevel,u32 Copy_u32SubGroupBitsNum);
NVIC_tenuErrorStatus NVIC_enuSetPriority(u8 Copy_u8IRQNum,u8 Copy_PrioRegValue);
NVIC_tenuErrorStatus NVIC_enuFilteringInterrupts(u8 Copy_u8PreemtLevel);
void NVIC_enuDisableIRQs(void);
void NVIC_enuEnableIRQs(void);
void NVIC_enuEnableFaults(void);
void NVIC_enuDisableFaults(void);

#endif /* NVIC_H_ */
