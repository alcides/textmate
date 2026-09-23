require ENV['TM_SUPPORT_PATH'] + '/lib/tm/executor'
require ENV['TM_SUPPORT_PATH'] + '/lib/tm/save_current_document'

# Match other language bundles: normal save handling and the shared output UI.
TextMate.save_if_untitled('ae')
executable = ENV['TM_AEON']
if executable.nil? || executable.empty?
  managed = File.expand_path('~/Library/Application Support/TextMate/LSP/Aeon/bin/aeon')
  executable = File.executable?(managed) ? managed : 'aeon'
end
TextMate::Executor.run(executable, ENV['TM_FILEPATH'],
  :chdir => File.dirname(ENV['TM_FILEPATH']),
  :use_hashbang => false)
