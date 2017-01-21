require "spec_helper"

describe URIParse do
  describe "#parse" do
    it "parses relative netpaths" do
      res = URIParse.parse("//foo-bar-baz")

      expect(res).to eq({uri: "//foo-bar-baz"})
    end

    it "parses relative netpaths with domain labels" do
      res = URIParse.parse("//foo.bar.baz")

      expect(res).to eq({uri: "//foo.bar.baz"})
    end
  end
end

