# frozen_string_literal: true

require_relative "ancient_ruby/version"
require_relative "ancient_ruby/runner"

module AncientRuby
  class Error < StandardError; end
  class ExecutionError < Error; end

  class << self
    # Evaluate a string of Ruby 0.49 code
    #
    # @param code [String] Ruby 0.49 code to evaluate
    # @return [String] Output from the Ruby 0.49 interpreter
    # @raise [ExecutionError] if the code fails to execute
    #
    # @example
    #   AncientRuby.eval('"Hello from 1994!".print')
    #   # => "Hello from 1994!"
    #
    def eval(code)
      Runner.eval(code)
    end

    # Evaluate a Ruby 0.49 script file
    #
    # @param path [String] Path to the Ruby 0.49 script
    # @param args [Array<String>] Arguments to pass to the script
    # @return [String] Output from the Ruby 0.49 interpreter
    # @raise [ExecutionError] if the script fails to execute
    # @raise [Errno::ENOENT] if the file doesn't exist
    #
    # @example
    #   AncientRuby.eval_file("examples/fizzbuzz.rb")
    #
    def eval_file(path, *args)
      Runner.eval_file(path, *args)
    end

    # Get the path to the Ruby 0.49 binary
    #
    # @return [String] Absolute path to the ruby049 executable
    #
    def binary_path
      Runner.binary_path
    end

    # Get the Ruby 0.49 version string
    #
    # @return [String] Version string from ruby-0.49 -v
    #
    def ruby049_version
      Runner.version
    end
  end
end
