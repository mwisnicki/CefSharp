{
  'target_defaults': {
    'msbuild_toolset': 'Windows7.1SDK',
  },
  'variables': {
    'msvs_multi_core_compile': 0,
  },
  'target_defaults': {
    'msvs_settings': {
      'VCCLCompilerTool': {
        'AdditionalOptions': ['/MP5'],
      },
    },
  },
}
