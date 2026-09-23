require ENV['TM_SUPPORT_PATH'] + '/lib/tm/executor'
require ENV['TM_SUPPORT_PATH'] + '/lib/tm/save_current_document'

# Match other language bundles: normal save handling and the shared output UI.
TextMate.save_if_untitled('ae')
executable = ENV['TM_AEON']
executable = 'aeon' if executable.nil? || executable.empty?
TextMate::Executor.run(executable, ENV['TM_FILEPATH'],
  :chdir => File.dirname(ENV['TM_FILEPATH']),
  :use_hashbang => false)
